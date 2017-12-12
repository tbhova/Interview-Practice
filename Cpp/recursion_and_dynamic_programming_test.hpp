#ifndef TEST_RECURSION_AND_DYNAMIC_PROGRAMMING_TEST_HPP
#define TEST_RECURSION_AND_DYNAMIC_PROGRAMMING_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "recursion_and_dynamic_programming.h"

using testing::Eq;

TEST(HanoiTest, PegTest) {
  Peg p;
  EXPECT_TRUE(p.empty());
  EXPECT_ANY_THROW(p.pop());
  EXPECT_ANY_THROW(p.top_and_pop());
  EXPECT_ANY_THROW(p.top());

  p.add(4);
  EXPECT_FALSE(p.empty());
  EXPECT_THAT(p.top(), Eq(4));
  EXPECT_FALSE(p.empty());
  EXPECT_ANY_THROW(p.add(5));
  p.add(3);
  EXPECT_THAT(p.top_and_pop(), Eq(3));
  EXPECT_FALSE(p.empty());
  p.pop();
  EXPECT_TRUE(p.empty());
}

TEST(HanoiTest, TestGame) {
  Peg p1;
  Peg p2;
  Peg p3;

  // Runs with no discs
  Hanoi(&p1, &p2, &p3, 0);

  p1.add(6);
  p1.add(4);
  p1.add(3);
  p1.add(2);
  p1.add(1);

  Hanoi(&p1, &p2, &p3, 5);

  EXPECT_THAT(p3.top_and_pop(), Eq(1));
  EXPECT_THAT(p3.top_and_pop(), Eq(2));
  EXPECT_THAT(p3.top_and_pop(), Eq(3));
  EXPECT_THAT(p3.top_and_pop(), Eq(4));
  EXPECT_THAT(p3.top_and_pop(), Eq(6));
  EXPECT_TRUE(p3.empty());
  EXPECT_TRUE(p2.empty());
  EXPECT_TRUE(p1.empty());
}

#endif //TEST_RECURSION_AND_DYNAMIC_PROGRAMMING_TEST_HPP
