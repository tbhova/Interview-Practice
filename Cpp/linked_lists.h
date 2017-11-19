#ifndef TEST_LINKED_LISTS_H
#define TEST_LINKED_LISTS_H

template <typename T>
class Node {
 public:
 Node() = default;
 ~Node() = default;

 Node* next = nullptr;
 T data;
};

void RemoveDuplicates(Node<int>* head);

void RemoveDuplicatesNoBuffer(Node<int>* head);

const Node<int>* nthNodeRec(const Node<int>& head, const int n);

#endif //TEST_LINKED_LISTS_H
