#include "SPSCLockFreeStack.h"

int main(){
	SPSCLockFreeStack ls;
	std::thread p1([&](){
		int i = 0;
		while(true){
			Node* n = new Node(++i);
			//LOG_INFO("pushing " << i << "in stack");
			ls.push(n);
		}
	});
	
	std::thread c1([&](){
		while(true){
			Node* n = ls.pop();
			if(n != nullptr){
				LOG_INFO("popped " << n->data << "from stack");
			}else{
				LOG_ERROR("nullptr");
			}
		}
	});


	if(p1.joinable()) p1.join();
	if(c1.joinable()) c1.join();
}