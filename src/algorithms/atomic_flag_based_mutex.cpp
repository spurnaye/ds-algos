#include <atomic>
#include <iostream>

struct AtomicFlagBasedMutex{
	AtomicFlagBasedMutex(): flg_(ATOMIC_FLAG_INIT){}
	void lock(){
		while(flg_.test_and_set(std::memory_order_acquire));
	}
	void unlock(){
		flg_.clear(std::memory_order_release);
	}
	
private:
	std::atomic_flag flg_;
};