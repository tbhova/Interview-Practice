#ifndef TEST_TEST_HPP
#define TEST_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace {
  using ::testing::Eq;

  class StringsAndArraysPr1 : public ::testing::Test {

  };

  TEST(Test, TestName) {
    EXPECT_THAT(1, Eq(1));
  }

}

#endif //TEST_TEST_HPP
