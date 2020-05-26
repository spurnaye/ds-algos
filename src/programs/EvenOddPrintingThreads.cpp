#include <iostream>
#include <thread>
#include <memory>

class EvenOddPrinter{
public:
   EvenOddPrinter(){
      evenThread_.reset(new std::thread(&EvenOddPrinter::printEven, this)); 
      oddThread_.reset(new std::thread(&EvenOddPrinter::printOdd, this)); 
   }
   ~EvenOddPrinter(){
        if(evenThread_->joinable()) evenThread_->join();
        if(oddThread_->joinable()) oddThread_->join();
    }
private:
    void printEven(){
        std::cout << "Even \n";
        while(true){
        std::unique_lock<std::mutex> lock_(mtx_);
        cv_.wait(lock_, [&](){
            return printStatus_ == PrintStatus::EVEN;
        });
        std::cout << start_ << "\n";
        start_++;
        printStatus_ = PrintStatus::ODD;
        cv_.notify_all();
        }
    }

    void printOdd(){
        std::cout << "Odd \n";
        while(true){
        std::unique_lock<std::mutex> lock_(mtx_);
        cv_.wait(lock_, [&](){
           return printStatus_ == PrintStatus::ODD;
        });
        std::cout << start_ << "\n";
        start_++;
        printStatus_ = PrintStatus::EVEN;
        cv_.notify_all();
        }
    }
 
    enum class PrintStatus {ODD, EVEN};
    std::unique_ptr<std::thread> evenThread_;
    std::unique_ptr<std::thread> oddThread_;
    std::mutex mtx_;
    std::condition_variable cv_;
    int start_ = 0;
    PrintStatus printStatus_ = PrintStatus::ODD;
};



int main(){
    EvenOddPrinter eop;
}
