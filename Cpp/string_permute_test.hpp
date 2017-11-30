#ifndef TEST_STRING_PERMUTE_TEST_HPP
#define TEST_STRING_PERMUTE_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "string_permute.h"

namespace {

 using ::testing::StrEq;

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
 }

}

#endif //TEST_STRING_PERMUTE_TEST_HPP
