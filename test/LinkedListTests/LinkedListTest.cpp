#include "LinkedListTest.h"

using namespace test;
TEST_F(LinkedListTest, NewObject) {
   ds::LinkedList ll;
   EXPECT_EQ(ll.size,0); 
}

TEST_F(LinkedListTest, PushBack) {
   ds::LinkedList ll;
   for(uint32_t i=0; i < 5; i++)
     ll.push_back(i);
   EXPECT_EQ(ll.size,5); 
}

TEST_F(LinkedListTest, PushFront) {
   ds::LinkedList ll;
   for(uint32_t i=0; i < 5; i++)
     ll.push_front(i);
   EXPECT_EQ(ll.size,5); 
}

TEST_F(LinkedListTest, PushFrontDataVerify) {
   ds::LinkedList ll;
   for(uint32_t i=0; i < 5; i++)
     ll.push_front(i);

   for(uint32_t i=4; i > 0; i--){
      EXPECT_EQ(ll.head()->getValue(), i);
      ll.pop_front();
   }
}

TEST_F(LinkedListTest, PopFrontEmptyLinkedList) {
   ds::LinkedList ll;
   for(uint32_t i=0; i < 5; i++)
     ll.pop_front();
   EXPECT_EQ(ll.size,0); 
}

TEST_F(LinkedListTest, PopFront) {
   ds::LinkedList ll;
   for(uint32_t i=0; i < 5; i++)
     ll.push_front(i);
   for(uint32_t i=0; i < 5; i++)
     ll.pop_front();
   EXPECT_EQ(ll.size,0); 
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
