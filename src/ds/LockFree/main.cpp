#include "SPSCIntQueue.h"
#include <thread>
#include <chrono>

int main(){
	SPSCIntQueue sp;
	std::thread producer([&sp](){
		int64_t x = 0;
		while(true){
			sp.push(++x);
			std::this_thread::sleep_for(std::chrono::microseconds(100));
		}
	});

	std::thread consumer([&sp](){
		int64_t x = 0;
		while(true){
			sp.pop();
			std::this_thread::sleep_for(std::chrono::microseconds(100));
		}
	});
	
	if(producer.joinable()) producer.join();
	if(consumer.joinable()) consumer.join();
}