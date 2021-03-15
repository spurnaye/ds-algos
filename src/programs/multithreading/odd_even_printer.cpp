#include <thread>
#include <future>
#include <iostream>
#include <condition_variable>

struct OddEvenPrinter{
	void evenPrinter(){
		std::unique_lock<std::mutex> lg(mtx);
		while(true){
			cv.wait(lg, [&](){return curr % 2 == 0;});
			std::cout << "evenPrinter " <<  curr++ << '\n';
			cv.notify_all();
		}
		cv.notify_all();
	}

	void oddPrinter(){
		std::unique_lock<std::mutex> lg(mtx);
		while(true){
			cv.wait(lg, [&](){return curr % 2 != 0;});
			std::cout << "oddPrinter " << curr++ << '\n'; 
			cv.notify_all();
		}
	}

	int curr = 0;
	std::condition_variable cv;
	std::mutex mtx;
};

int main(){
	OddEvenPrinter oep;
	std::thread te([&](){
		oep.evenPrinter();
	});
	std::thread to([&](){
		oep.oddPrinter();
	});

	if(te.joinable()) te.join();
	if(to.joinable()) to.join();
	
}
