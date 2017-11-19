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