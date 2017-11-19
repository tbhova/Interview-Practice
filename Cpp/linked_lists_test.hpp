#ifndef TEST_LINKED_LISTS_TEST_HPP
#define TEST_LINKED_LISTS_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "linked_lists.h"

using ::testing::IsNull;
using ::testing::Eq;

TEST(Problem1_1, Test) {
  Node<int>* ptr = nullptr;
  RemoveDuplicates(ptr);

  Node<int> head;
  head.data = 1;
  head.next = new Node<int>;
  ptr = head.next;
  ptr->data = -1;

  ptr->next = new Node<int>;
  ptr = ptr->next;
  ptr->data = 1;

  ptr->next = new Node<int>;
  ptr = ptr->next;
  ptr->data = 1;

  ptr->next = new Node<int>;
  ptr = ptr->next;
  ptr->data = 1;

  RemoveDuplicates(&head);
  EXPECT_THAT(head.next->next, IsNull());
  EXPECT_THAT(head.next->data, Eq(-1));
}

#endif //TEST_LINKED_LISTS_TEST_HPP
