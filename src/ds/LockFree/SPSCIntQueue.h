#include <iostream>
#include <atomic>

// open ended SPSC Queue
struct SPSCIntQueue{
   SPSCIntQueue(){
   	  head_ = new Node(-1, true);
   	  tail_ = new Node(-1, true);
   	  head_->next_ = tail_;
   	  tail_->prev_ = head_;
   };

   SPSCIntQueue& operator=(const SPSCIntQueue& rhs) = delete;
   SPSCIntQueue(const SPSCIntQueue& rhs) = delete;

   void push(int64_t data){
       Node* newNode = new Node(data);
       tryLock();
       newNode->next_ = tail_;
       tail_->prev_->next_ = newNode;
       tail_->prev_ = newNode;
       std::cout << "pushed " << data;
       clearLock();
   }

   int64_t pop(){
       tryLock();
       Node* next = head_->next_;
       head_->next_ = next->next_;
       next->next_->prev_ = head_;
       clearLock();
       std::cout << "popped " << next->getData();
       return next->getData();
   }

   private:
   	 struct Node{
   	 		explicit Node(int64_t data, bool sentinal_node = false):
   	 	 	data_{data}, sentinal_node_{sentinal_node}{};

   	 	 	int64_t getData(){return data_;}
   	 		Node* next_ = nullptr;
   	 		Node* prev_ = nullptr;
   		private:
   			int64_t data_ = -1;
   			bool sentinal_node_ = false;
   	 };

   	 bool tryLock(){
   	 	while(flag_.test_and_set(std::memory_order_acquire)){};
   	 	return true;
   	 }

   	 void clearLock(){
   	 	flag_.clear(std::memory_order_release);
   	 }

     Node* head_;
     Node* tail_;
     std::atomic_flag    flag_;
};