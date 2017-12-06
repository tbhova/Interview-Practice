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

  TEST(StringTest, Reverse) {
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

  TEST(StringPermuteTest, TestPermutations) {
    EXPECT_FALSE(Permute("", nullptr));
    std::string out;
    EXPECT_TRUE(Permute("", &out));
    EXPECT_THAT(out, StrEq(""));

    EXPECT_FALSE(Permute("aa", &out));
    EXPECT_FALSE(Permute("aaa", &out));
    EXPECT_FALSE(Permute("abbb", &out));
    EXPECT_FALSE(Permute("bababb", &out));

    EXPECT_TRUE(Permute("abc", &out));
    EXPECT_THAT(out, StrEq("abc"));

    EXPECT_TRUE(Permute("abc", &out));
    EXPECT_THAT(out, StrEq("abc"));

    EXPECT_TRUE(Permute("aab", &out));
    EXPECT_THAT(out, StrEq("aba"));

    EXPECT_TRUE(Permute("abb", &out));
    EXPECT_THAT(out, StrEq("bab"));

    EXPECT_TRUE(Permute("abbaab", &out));
    EXPECT_THAT(out, StrEq("ababab"));

    EXPECT_TRUE(Permute("abbaabccdde", &out));
    EXPECT_THAT(out, StrEq("abcdabedacb"));
  }

}

#endif //TEST_TEST_HPP
