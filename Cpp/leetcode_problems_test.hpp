#ifndef TEST_LEETCODE_PROBLEMS_TEST_HPP
#define TEST_LEETCODE_PROBLEMS_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "leetcode_problems.h"

using ::testing::StrEq;
using ::testing::AnyOf;

TEST(LeetcodeTest, TestPali) {
  EXPECT_THAT(LongestPalindrome("babad"), AnyOf(StrEq("bab"), StrEq("aba")));
  EXPECT_THAT(LongestPalindrome("cbbd"), StrEq("bb"));
  EXPECT_THAT(LongestPalindrome("ccbbcc"), StrEq("ccbbcc"));
  EXPECT_THAT(LongestPalindrome("a"), StrEq("a"));
  EXPECT_THAT(LongestPalindrome(""), StrEq(""));
  EXPECT_THAT(LongestPalindrome("abcda"), AnyOf(StrEq("a"), StrEq("b"), StrEq("c"), StrEq("d")));
}

#endif //TEST_LEETCODE_PROBLEMS_TEST_HPP