#ifndef TEST_STACKS_AND_QUEUES_TEST_HPP_HPP
#define TEST_STACKS_AND_QUEUES_TEST_HPP_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "stacks_and_queues.h"

TEST(StacksAndQueuesTest, SortStackTest) {
  EXPECT_FALSE(SortStack(nullptr));

  std::vector<int>vec {1,4,5,3,1,4,5,0,-14,20,-44};
  std::stack<int> data;
  for (int i : vec) {
    data.push(i);
  }
  EXPECT_TRUE(SortStack(&data));
  EXPECT_THAT(data.top(), Eq(-44));
  data.pop();
  EXPECT_THAT(data.top(), Eq(-14));
  data.pop();
  EXPECT_THAT(data.top(), Eq(0));
  data.pop();
  EXPECT_THAT(data.top(), Eq(1));
  data.pop();
  EXPECT_THAT(data.top(), Eq(1));
  data.pop();
  EXPECT_THAT(data.top(), Eq(3));
  data.pop();
  EXPECT_THAT(data.top(), Eq(4));
  data.pop();
  EXPECT_THAT(data.top(), Eq(4));
  data.pop();
  EXPECT_THAT(data.top(), Eq(5));
  data.pop();
  EXPECT_THAT(data.top(), Eq(5));
  data.pop();
  EXPECT_THAT(data.top(), Eq(20));
  data.pop();
  EXPECT_THAT(data, testing::IsEmpty());
}

#endif //TEST_STACKS_AND_QUEUES_TEST_HPP_HPP
