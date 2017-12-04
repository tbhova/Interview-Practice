#include "stacks_and_queues.h"

bool SortStack(std::stack<int>* in) {
  if (!in || in->empty()) return false;
  std::stack<int> s;
  do {
    int tmp = in->top();
    in->pop();
    while (!s.empty() && tmp < s.top()) {
      int s_val = s.top();
      in->push(s_val);
      s.pop();
    }
    s.push(tmp);
  } while(!in->empty());
  while (!s.empty()) {
    int s_val = s.top();
    in->push(s_val);
    s.pop();
  }
  return true;
}
