#include "NodeBasedQueueHeadOnly.h"
#include <thread>
#include <vector>

int main(){
	NodeBasedQueueHeadOnly nl;
	std::vector<std::thread> vt;
	for(int i =0; i < 5; ++i){
		std::thread t([&](){
				while(true){
					Node* node = new Node(i);
					std::cout << "add val "<< i << '\n';
					nl.add(node);
				}
		});
		vt.push_back(std::move(t));
	}
	for(int i =0; i < 5; ++i){
	std::thread t([&](){
		while(true){
			Node* n = nl.try_pop();
			if(n) {
				std::cout << "delete "<< n->data << '\n';
				delete n;
			}
		}
		});
		vt.push_back(std::move(t));
	}
	for(auto& t: vt) 
			t.join();
}