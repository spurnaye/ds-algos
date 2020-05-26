#include "LinkedList/linkedlist.h"
#include "SmartPointer/SmartPointer.h"
using namespace ds;
int main(int argc, const char *argv[]){
   LinkedList ll;
   for(int i = 10; i >= 0; i--)
       ll.push_front(i);
   
   for(int i = 0; i <= 10; i++)
       ll.push_back(i);
   ll.print(); 
   std::cout << "Linked List initialized \n"; 
  

   return 0;
}
