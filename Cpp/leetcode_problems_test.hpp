#ifndef TEST_LEETCODE_PROBLEMS_TEST_HPP
#define TEST_LEETCODE_PROBLEMS_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "leetcode_problems.h"

using ::testing::StrEq;
using ::testing::AnyOf;

TEST(LeetcodeTest, TestPali) {
  EXPECT_THAT(LongestPalindrome("babad"), AnyOf(StrEq("bab"), StrEq("aba")));
  EXPECT_THAT(LongestPalindrome("cbbbb"), StrEq("bbbb"));
  EXPECT_THAT(LongestPalindrome("ccbbcc"), StrEq("ccbbcc"));
  EXPECT_THAT(LongestPalindrome("a"), StrEq("a"));
  EXPECT_THAT(LongestPalindrome(""), StrEq(""));
  EXPECT_THAT(LongestPalindrome("abcda"), AnyOf(StrEq("a"), StrEq("b"), StrEq("c"), StrEq("d")));
}

TEST(LeetcodeTest, TestConvertZigZag) {
  EXPECT_THAT(convert("PAYPALISHIRING", 3), StrEq("PAHNAPLSIIGYIR"));
  EXPECT_THAT(convert("AB", 4), StrEq("AB"));
  EXPECT_THAT(convert("AB", 1), StrEq("AB"));
}

#endif //TEST_LEETCODE_PROBLEMS_TEST_HPP
