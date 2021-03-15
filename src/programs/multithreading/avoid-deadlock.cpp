#include <mutex>
#include <thread>
#include <iostream>
#include <sstream>
struct X;
void swap(X& lhs, X& rhs);

struct X{
	explicit X(int x):to_be_exchanged{x}{};
    int to_be_exchanged;
    std::mutex mtx;

    friend void swap(X& lhs, X& rhs){
	if(&lhs == &rhs){
		return;
	}

	std::lock(lhs.mtx, rhs.mtx);
	std::lock_guard<std::mutex> lock_a(lhs.mtx, std::adopt_lock);
	std::lock_guard<std::mutex> lock_b(rhs.mtx, std::adopt_lock);
	auto thread_id = std::this_thread::get_id();
	std::cout << "swaping "<< lhs.to_be_exchanged << " with "<< rhs.to_be_exchanged << " by " 
	<< thread_id << "\n";
	if(lhs.to_be_exchanged == rhs.to_be_exchanged){
		std::stringstream ss;
		ss <<  "same value error in thread ";
		ss << thread_id;
		throw std::runtime_error(ss.str());
	}
	std::swap(lhs.to_be_exchanged, rhs.to_be_exchanged);
}
};



int main(){
	X x1(10);
	X x2(20);
	std::thread t1([&](){
		while(true){
			swap(x1, x2);
		}
	});

	std::thread t2([&](){
		while(true){
			swap(x2, x1);
		}
	});


	if(t1.joinable()) t1.join();
	if(t2.joinable()) t2.join();
}