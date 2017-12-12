#ifndef TEST_RECURSION_AND_DYNAMIC_PROGRAMMING_H
#define TEST_RECURSION_AND_DYNAMIC_PROGRAMMING_H

#include <memory>
#include <stack>

// Problem 8.6
class Peg {
public:
  void pop() { CheckNotEmpty(); s.pop(); }

  void add(int i);

  int top() const { CheckNotEmpty(); return s.top(); }

  int top_and_pop();

  bool empty() const { return s.empty(); }

private:
  void CheckNotEmpty() const { if (empty()) throw "Empty stack"; }

  std::stack<int> s;
};

void Hanoi(Peg* from, Peg* inter, Peg* to, int n);

#endif //TEST_RECURSION_AND_DYNAMIC_PROGRAMMING_H
