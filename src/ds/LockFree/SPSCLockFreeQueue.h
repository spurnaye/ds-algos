#include "common/include_header.h"

struct Node
{
	explicit Node(int d): data{d}, next {nullptr}{}
	int data;
	std::atomic<Node*> next;
};

struct SPSCLockFreeQueue{
	void push(int d){
		Node* node = new Node(d);
		LOG_INFO("Pushing "<< d << " into queue");
		for(;;){
			Node* currTail = tail.load(std::memory_order_acquire); // Node*
			if(currTail == nullptr){
				tail.store(node,std::memory_order_release);
				return;
			}
			Node * null = nullptr;
			while(tail && tail.load()->next && 
					tail.load()->next.compare_exchange_strong(null,node) && 
					tail.compare_exchange_strong(currTail, node));
			if(head.load() == null) head.compare_exchange_strong(null, node);
			break;
		}
	}

	Node* pop(){
		Node* currHead;
		for(;;){
			currHead = head.load(std::memory_order_acquire);
			if(currHead == nullptr) return nullptr;
			while(head && !head.compare_exchange_strong(currHead, head.load()->next));
			currHead->next.store(nullptr);
			break;
		}
		if(currHead) LOG_INFO("Popped "<< currHead->data << " from queue");
		return currHead;
	}

	std::atomic<Node*> head;
	std::atomic<Node*> tail;
};
