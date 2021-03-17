#include <iostream>
#include <atomic>

struct Node{
	explicit Node(int val): data{val}{};
	int data;
	std::atomic<Node*> next;
};

struct NodeBasedQueueHeadOnly{
	NodeBasedQueueHeadOnly():head(nullptr){};
	void add(Node* node){
		while(true){
			Node* curr = head.load(std::memory_order_acquire);
			while(node->next.compare_exchange_weak(curr, node->next, std::memory_order_release));
			break;
		}
	}

	Node* try_pop(){
		Node * curr = head.load(std::memory_order_acquire);
		while(curr && curr->next){
			curr = curr->next;
		}
		if(curr == nullptr) return curr;
		Node* next = curr->next;
		while(!curr->next.compare_exchange_weak(next, nullptr, std::memory_order_release));
		return next;
	}

private:
	std::atomic<Node*> head;
};
