#include <thread>
#include <atomic>
#include "common/include_header.h"

struct MyMutex{
	void lock(){
		my_flag.test_and_set(std::memory_order_acq_rel);
	}
	void unlock(){
		my_flag.clear(std::memory_order_release);
	}

	std::atomic_flag my_flag = ATOMIC_FLAG_INIT;
};

MyMutex mtx;

void fun(int& i){
	std::lock_guard<MyMutex> ag(mtx);
	LOG_INFO(++i);
}

int main(){
	int i = 0;
	std::thread t1([&](){
		while(true) fun(i);
	});

	std::thread t2([&](){
		while(true) fun(i);
	});

	if(t1.joinable()) t1.join();
	if(t2.joinable()) t2.join();
}