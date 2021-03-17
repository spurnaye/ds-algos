#include "SPSCLockFreeQueue.h"

int main(){
	SPSCLockFreeQueue q;

	std::thread prod([&](){
		int i = 0;
		while(true){
			q.push(++i);
		}
	});
	std::thread cons([&](){
		while(true){
			Node* node = q.pop();
			delete node;
		}
	});

	if(prod.joinable()) prod.join();
	if(cons.joinable()) cons.join();
}