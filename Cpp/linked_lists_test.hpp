#ifndef TEST_LINKED_LISTS_TEST_HPP
#define TEST_LINKED_LISTS_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "linked_lists.h"

using ::testing::IsNull;
using ::testing::Eq;
using ::testing::Not;

TEST(Problem1_1, RemoveDuplicates) {
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

TEST(Problem1_1, RemoveDuplicatesNoBuffer) {
  Node<int>* ptr = nullptr;
  RemoveDuplicatesNoBuffer(ptr);

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

  RemoveDuplicatesNoBuffer(&head);
  EXPECT_THAT(head.next->next, IsNull());
  EXPECT_THAT(head.next->data, Eq(-1));
}

TEST(Problem1_2, GetNthNodeRec) {
  Node<int> head;
  head.data = 1;
  head.next = new Node<int>;
  Node<int>* ptr = head.next;
  ptr->data = 2;

  ptr->next = new Node<int>;
  ptr = ptr->next;
  ptr->data = 3;

  ptr->next = new Node<int>;
  ptr = ptr->next;
  ptr->data = 4;

  ptr->next = new Node<int>;
  ptr = ptr->next;
  ptr->data = 5;

  ASSERT_THAT(nthNodeRec(head, 0), Not(IsNull()));
  ASSERT_THAT(nthNodeRec(head, 1), Not(IsNull()));
  ASSERT_THAT(nthNodeRec(head, 2), Not(IsNull()));
  ASSERT_THAT(nthNodeRec(head, 3), Not(IsNull()));;
  ASSERT_THAT(nthNodeRec(head, 4), Not(IsNull()));
  EXPECT_THAT(nthNodeRec(head, 0)->data, Eq(5));
  EXPECT_THAT(nthNodeRec(head, 1)->data, Eq(4));
  EXPECT_THAT(nthNodeRec(head, 2)->data, Eq(3));
  EXPECT_THAT(nthNodeRec(head, 3)->data, Eq(2));
  EXPECT_THAT(nthNodeRec(head, 4)->data, Eq(1));
  EXPECT_THAT(nthNodeRec(head, 5), IsNull());
  EXPECT_THAT(nthNodeRec(head, -1), IsNull());
}

#endif //TEST_LINKED_LISTS_TEST_HPP
