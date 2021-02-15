#include <thread>
#include <mutex>
#include <unistd.h>
#include <iostream>
#include <shared_mutex>
std::mutex mtx1;

struct Deadlock{
	void operator ()(){
		std::thread t1([](){
			while(true){
				std::cout << "Thread: "<< std::this_thread::get_id() << '\n';
				if(mtx1.try_lock()){
					std::cout << "Thread: "<< std::this_thread::get_id() << " mtx1 lock";
					if(mtx2.try_lock()){
						std::cout << "Thread: "<< std::this_thread::get_id() << " mtx2 lock";
					    mtx2.unlock();
					}
					mtx1.unlock();
				}
				
			}
		});

		std::thread t2([](){
			while(true){
				if(mtx2.try_lock()){
					std::cout << "Thread: "<< std::this_thread::get_id() << " mtx2 lock";
					if(mtx1.try_lock()){
						std::cout << "Thread: "<< std::this_thread::get_id() << " mtx1 lock";
						mtx1.unlock();
					}
					mtx2.unlock();
				}
			}
		});
		if(t1.joinable()) t1.join();
		if(t2.joinable()) t2.join();
	}

};
int main(){
	Deadlock dl;
	dl(); 
}