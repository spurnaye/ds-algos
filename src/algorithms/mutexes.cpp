#include <thread>
#include <memory>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <mutex>

std::mutex mtx_;
struct ThreadClient{
	virtual void process() = 0;
};

struct SleepyClient: public ThreadClient{
	void process() override {
		std::cout << "Sleeping thread "<< std::this_thread::get_id() << '\n';
    if(mtx_.try_lock()){
		  usleep(100);
      mtx_.unlock();
    }
	}
};

struct SuperSleepyClient: public ThreadClient{
	void process() override {
		std::cout << "SuperSleeping thread "<< std::this_thread::get_id() << '\n';
    if(mtx_.try_lock()){
		  usleep(1000);
      mtx_.unlock();
    }
	}
};

struct Thread{
    void start(int count){
    	auto lambda = [this]()->void{
    		while(true){
    			for(auto& c: clients_){
    				c->process();
    			}
    		}
    	};
      for(int i = 0; i < count; ++i){
    	   threads_.emplace_back(std::thread(lambda));
      }
    }
	
    ~Thread(){
    	for(auto& th: threads_){
        if(th.joinable())
    		  th.join();
        }
    }

    void addClient(ThreadClient* cl){clients_.push_back(cl);}

	private:
	std::vector<std::thread> threads_;
	std::vector<ThreadClient*> clients_;
};


int main(){
   Thread th;
   th.start(5);
   SleepyClient sc;
   SuperSleepyClient ssc;
   th.addClient(&sc);
   th.addClient(&ssc);
}