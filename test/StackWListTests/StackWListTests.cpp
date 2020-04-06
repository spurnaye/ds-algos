#include "StackWListTests.h"

using namespace test;
TEST_F(StackWListTest, NewObject) {
   ds::StackWLinkedList ll;
   EXPECT_EQ(ll.size,0); 
}

TEST_F(StackWListTest, PushBack) {
   ds::StackWLinkedList ll;
   for(uint32_t i=0; i < 5; i++)
     ll.push(i);
   EXPECT_EQ(ll.size,5); 
}

TEST_F(StackWListTest, PushFront) {
   ds::StackWLinkedList ll;
   for(uint32_t i=0; i < 5; i++)
     ll.push(i);
   EXPECT_EQ(ll.size,5); 
}

TEST_F(StackWListTest, PushFrontDataVerify) {
   ds::StackWLinkedList ll;
   for(uint32_t i=0; i < 5; i++)
     ll.push(i);

   for(uint32_t i=4; i > 0; i--){
      EXPECT_EQ(ll.top()->getValue(), i);
      ll.pop();
   }
}

TEST_F(StackWListTest, PopFrontEmptyStackWLinkedList) {
   ds::StackWLinkedList ll;
   for(uint32_t i=0; i < 5; i++)
     ll.pop();
   EXPECT_EQ(ll.size,0); 
}

TEST_F(StackWListTest, PopFront) {
   ds::StackWLinkedList ll;
   for(uint32_t i=0; i < 5; i++)
     ll.push(i);
   for(uint32_t i=0; i < 5; i++)
     ll.pop();
   EXPECT_EQ(ll.size,0); 
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
