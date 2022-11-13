#include <gtest/gtest.h>

#include <iostream>
#include <cassert>

#include <FString>

using std::cout;
using std::endl;
using namespace lshaocong;

TEST(value, value_npos_Test){
  EXPECT_EQ(-1, fstring::npos);
}

TEST(ctor, ctor_test){
  fstring fs;
  EXPECT_EQ(fs.size(), 0);
  EXPECT_EQ(fs.capacity(), 0);
  const char *ms = "microsoft";

  fstring fs2(ms);
  EXPECT_EQ(fs2.size(), strlen(ms));

  fstring fs3(100, 'c');
  EXPECT_EQ(fs3.size(), 100);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}