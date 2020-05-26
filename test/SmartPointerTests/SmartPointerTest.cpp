#include "SmartPointerTest.h"

using namespace test;
TEST_F(SmartPointerTest, NewObject) {
   int a = 100;
   ds::SmartPointer sp(&a);
   EXPECT_EQ(sp.refcount(),1); 
}

TEST_F(SmartPointerTest, CopyConstructorTest) {
   int a = 100;
   ds::SmartPointer sp(&a);
   auto pointerCopy = sp;
   EXPECT_EQ(sp.refcount(),2); 
}

TEST_F(SmartPointerTest, CopyAssignmentTest) {
   int a = 100;
   ds::SmartPointer sp(&a);
   ds::SmartPointer sp2(&a);
   sp2 = sp;;
   EXPECT_EQ(sp.refcount(),2); 
}

TEST_F(SmartPointerTest, CopyAssignmentiSelfTest) {
   int a = 100;
   ds::SmartPointer sp(&a);
   sp = sp;;
   EXPECT_EQ(sp.refcount(),1); 
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
