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

  TEST(StringsArraysTest, TestIsUnique) {
    EXPECT_TRUE(IsUnique(""));
    const string unique = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890-*/\\[]";
    EXPECT_TRUE(IsUnique(unique));
    EXPECT_FALSE(IsUnique(unique + "a"));
    EXPECT_FALSE(IsUnique("a" + unique));
  }

  TEST(StringsArraysTest, Reverse) {
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

  TEST(StringsArraysTest, TestPermutations) {
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

  TEST(StringsArraysTest, TestBinarySearch) {
    EXPECT_THAT(BinarySearch(std::vector<int>(), -7), Eq(-1));

    EXPECT_THAT(BinarySearch(std::vector<int>{9}, 1), Eq(-1));
    EXPECT_THAT(BinarySearch(std::vector<int>{9}, 9), Eq(0));

    EXPECT_THAT(BinarySearch(std::vector<int>{1, 2, 4, 5, 6, 8, 10}, -7), Eq(-1));
    EXPECT_THAT(BinarySearch(std::vector<int>{1, 2, 4, 5, 6, 8, 10}, 1), Eq(0));
    EXPECT_THAT(BinarySearch(std::vector<int>{1, 2, 4, 5, 6, 8, 10}, 2), Eq(1));
    EXPECT_THAT(BinarySearch(std::vector<int>{1, 2, 4, 5, 6, 8, 10}, 4), Eq(2));
    EXPECT_THAT(BinarySearch(std::vector<int>{1, 2, 4, 5, 6, 8, 10}, 5), Eq(3));
    EXPECT_THAT(BinarySearch(std::vector<int>{1, 2, 4, 5, 6, 8, 10}, 6), Eq(4));
    EXPECT_THAT(BinarySearch(std::vector<int>{1, 2, 4, 5, 6, 8, 10}, 8), Eq(5));
    EXPECT_THAT(BinarySearch(std::vector<int>{1, 2, 4, 5, 6, 8, 10}, 10), Eq(6));
    EXPECT_THAT(BinarySearch(std::vector<int>{1, 2, 4, 5, 6, 8, 10, 11}, 10), Eq(6));
    EXPECT_THAT(BinarySearch(std::vector<int>{1, 2, 4, 5, 6, 8, 10, 11}, 11), Eq(7));
  }

}

#endif //TEST_TEST_HPP
