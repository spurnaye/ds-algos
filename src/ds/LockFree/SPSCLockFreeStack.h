#include "common/include_header.h"


struct Node{
	explicit Node(int d): data{d}, next{nullptr}{};
	int data;
	std::atomic<Node*> next;
};


struct SPSCLockFreeStack
{
	void push(Node* node){
		node->next.store(head);
		Node* next = node->next;
		while(!head && head.compare_exchange_weak(next, node));
	}

	Node* pop(){
		LOG_INFO("in pop");
		Node* curr = head.load(std::memory_order_acquire);
		LOG_INFO("in pop");
		if(curr == nullptr) return nullptr;
		while(curr && !head.compare_exchange_weak(curr, curr->next));
		LOG_INFO("in pop");
		if(curr){
			LOG_INFO("acquired "<<curr->data << '\n');
		}else{
			return nullptr;
		}
	}

	std::atomic<Node*> head;
};
