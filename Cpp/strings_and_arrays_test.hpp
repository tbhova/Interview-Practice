#ifndef TEST_TEST_HPP
#define TEST_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "strings_and_arrays.h"

namespace {
  using ::testing::Eq;
  using ::testing::HasSubstr;
  using ::testing::SizeIs;
  using ::testing::StrEq;

  TEST(Problem1_1, TestIsUnique) {
    EXPECT_TRUE(IsUnique(""));
    const string unique = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890-*/\\[]";
    EXPECT_TRUE(IsUnique(unique));
    EXPECT_FALSE(IsUnique(unique + "a"));
    EXPECT_FALSE(IsUnique("a" + unique));
  }

  TEST(Problem1_2, Reverse) {
    string in = "";
    Reverse(in);
    EXPECT_THAT(in, StrEq(""));

    string in2 = "four";
    Reverse(in2);
    EXPECT_THAT(in2, StrEq("ruof"));

    string in3 = "qwert";
    string in3_og = in3;
    Reverse(in3);
    EXPECT_THAT(in3, StrEq("trewq"));
    Reverse(in3);
    EXPECT_THAT(in3, in3_og);
  }

}

#endif //TEST_TEST_HPP
