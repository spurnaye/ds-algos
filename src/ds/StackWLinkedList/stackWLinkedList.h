#include <iostream>
#include "../common/node.h"

namespace ds{
struct StackWLinkedList{
   StackWLinkedList(){
       top_ = new Node(-1);
   }

   virtual ~StackWLinkedList(){
       Node * curr = top_;
       while(curr->next_ != nullptr){
           if(curr != nullptr) break;
           temp_ = curr->next_;
           delete curr;
           curr = temp_;
       }
       delete curr;
   }

   Node* top(){return top_->next_;}

   void push(int value){
       Node* node = new Node(value);
       if(top_->next_ == nullptr){
           top_->next_ = node;
       }else{
           temp_ = top_->next_;
           node->next_ = temp_;
           top_->next_ = node;
       }
       size++;
       std::cout << "Add node with value "<< node->getValue() << "\n";
   }
   
   void pop(){
       temp_ = top_->next_;
       if(temp_ == nullptr) return;
       if(temp_->next_ == nullptr){
           top_->next_ = nullptr;
       }else{
           top_->next_ = temp_->next_;
       }
       delete temp_;
       size--;
   }

   void print(){
     for(temp_ = top_->next_;;){
         std::cout << temp_->getValue() << "\n";
         if(temp_->next_ == nullptr) break;
         temp_ = temp_->next_;
     }
   }
    
   size_t size = 0;
private:
    Node* top_ = nullptr;
    Node* temp_;
};

}