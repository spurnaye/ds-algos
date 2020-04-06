#include <iostream>
#include "../common/node.h"

namespace ds{
struct LinkedList{
   LinkedList(){
       head_ = new Node(-1);
   }

   virtual ~LinkedList(){
       Node * curr = head_;
       while(curr->next_ != nullptr){
           if(curr != nullptr) break;
           temp_ = curr->next_;
           delete curr;
           curr = temp_;
       }
       delete curr;
   }

   void push_front(int value){
       Node* node = new Node(value);
       if(head_->next_ == nullptr){
           head_->next_ = node;
       }else{
           temp_ = head_->next_;
           node->next_ = temp_;
           head_->next_ = node;
       }
       size++;
   }

   void push_back(int value){
     Node* node = new Node(value);
     temp_ = head_;
     while(temp_->next_ != nullptr){
       temp_ = temp_->next_;
     }
     temp_->next_ = node;
     size++;
   }

   void pop_front(){
     temp_ = head_->next_;
     if(temp_ == nullptr) return;
     if(temp_->next_ != nullptr) head_->next_ = temp_->next_;
     delete temp_;
     temp_ = nullptr;
     size--;
   }
   
   Node* head(){
     if(head_->next_ == nullptr) return nullptr;
     return head_->next_;
   }
   
   Node* back(){
     temp_ = head_->next_;
     while(temp_->next_ == nullptr) {
       temp_ = temp_->next_;
     }
     return temp_;
   }

   void print(){
     for(temp_ = head_->next_;;){
         std::cout << temp_->getValue() << "\n";
         if(temp_->next_ == nullptr) break;
         temp_ = temp_->next_;
     }
   }
    
   size_t size = 0;
private:
    Node* head_ = nullptr;
    Node* temp_;
};

}