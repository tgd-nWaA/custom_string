#include "gtest/gtest.h"
#include "MyString.h"

TEST(MystringTest, testConstructor) {
   MyString str1;
   MyString str2("hello ");
   EXPECT_EQ(str2.Length(), 6);
   str1 = str2;  
   MyString str3 = "how are you";
   MyString str4 = str2+str3;
   EXPECT_EQ(strcmp(str4.c_str(),"hello how are you"), 0);
   const char* str = str4.c_str();
   
}
