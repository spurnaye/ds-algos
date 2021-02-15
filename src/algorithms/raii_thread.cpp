#include <thread>
#include <memory>
#include <vector>
#include <unistd.h>
#include <iostream>

struct ThreadClient{
	virtual void process() = 0;
};

struct SleepyClient: public ThreadClient{
	void process() override {
		std::cout << "Sleeping thread "<< std::this_thread::get_id() << '\n';
		usleep(100);
	}
};

struct SuperSleepyClient: public ThreadClient{
	void process() override {
		std::cout << "SuperSleeping thread "<< std::this_thread::get_id() << '\n';
		usleep(1000);
	}
};

struct Thread{
    void start(){
    	auto lambda = [this]()->void{
    		while(true){
    			for(auto& c: clients_){
    				c->process();
    			}
    		}
    	};
    	thread_.reset(new std::thread(lambda));
    }
	
    ~Thread(){
    	if(thread_->joinable())
    		thread_->join();
    }

    void addClient(ThreadClient* cl){clients_.push_back(cl);}

	private:
	std::unique_ptr<std::thread> thread_;
	std::vector<ThreadClient*> clients_;
};


int main(){
   Thread th;
   th.start();
   SleepyClient sc;
   SuperSleepyClient ssc;
   th.addClient(&sc);
   th.addClient(&ssc);
}