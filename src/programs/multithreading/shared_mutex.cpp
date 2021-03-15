#include "common/include_header.h"

struct Incrementor{
	void increment(){
		std::lock_guard<std::shared_mutex> lg(smtx);
		++curr;
	}

	void print(){
		LOG_INFO("curr "<< curr);
	}

private:
	int curr = 0;
	std::shared_mutex smtx;
};
int main(){
	Incrementor ic;
	std::thread t1([&](){
		while(true){
			ic.increment();
			ic.print();
		}
	});

	std::thread t2([&](){
		while(true){
			ic.increment();
			ic.print();
		}
	});

	std::thread t3([&](){
		while(true){
			ic.increment();
			ic.print();
		}
	});


	if(t1.joinable()) t1.join();
	if(t2.joinable()) t2.join();
	if(t3.joinable()) t3.join();
}