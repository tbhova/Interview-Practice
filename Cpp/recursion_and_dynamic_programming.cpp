#include "recursion_and_dynamic_programming.h"

void Peg::add(int i) {
  if (!s.empty() && i > top()) {
    throw "Invalid add, disc must be smaller.";
  }
  s.push(i);
}

int Peg::top_and_pop() {
  int ret = top();
  pop();
  return ret;
}

void Hanoi(Peg* from, Peg* inter, Peg* to, int n) {
  if (n <= 0) return;

  // Move n-1 to the intermediate so that we may move n to the to peg.
  Hanoi(from, to, inter, n-1);
  to->add(from->top_and_pop());

  // Move the n-1 peg off the intermediate peg to the to peg.
  Hanoi(inter, from, to, n-1);
}
