#include "linked_lists.h"

#include <unordered_set>
#include <bits/unordered_set.h>

void RemoveDuplicates(Node<int>* head) {
  std::unordered_set<int> seen;
  if (head == nullptr || head->next == nullptr) {
    return;
  }
  seen.insert(head->data);
  Node<int>* ptr_last = head;
  Node<int>* ptr = head->next;
  while (ptr != nullptr) {
    if (seen.find(ptr->data) != seen.end()) {
      ptr_last->next = ptr->next;
      if (ptr->next == nullptr) {
        return;
      }
    } else {
      seen.insert(ptr->data);
      ptr_last = ptr;
    }
    ptr = ptr->next;
  }
}

void RemoveDuplicatesNoBuffer(Node<int>* head) {
  if (head == nullptr || head->next == nullptr) {
    return;
  }
  Node<int>* ptr_last = head;
  Node<int>* ptr = head->next;
  while (ptr != nullptr) {
    Node<int>* iter = head;
    bool found = false;
    while (iter != ptr) {
      if (iter->data == ptr->data) {
        // delete ptr
        ptr_last->next = ptr->next;
        found = true;
        break;
      }
      iter = iter->next;
    }
    if (!found) {
      ptr_last = ptr;
    }
    ptr = ptr->next;
  }
}

const Node<int>* GetNodeRec(const Node<int>* node, const int n, int* depth) {
  if (node == nullptr) {
    return node;
  }
  const Node<int>* ret = GetNodeRec(node->next, n, depth);
  if (ret == nullptr) {
    if (*depth == n) {
      return node;
    }
    (*depth)++;
  }
  return ret;
}

const Node<int>* nthNodeRec(const Node<int>& head, const int n) {
  int depth = 0;
  return GetNodeRec(&head, n, &depth);
}