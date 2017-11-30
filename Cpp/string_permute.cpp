#include <vector>
#include <queue>
#include "string_permute.h"

struct Letter {
  char c;
  int count;

  bool operator<(const Letter& rhs) const {
    return count < rhs.count;
  }
};

bool Permute(const std::string& in, std::string* out) {
  if (!out) return false;
  else if (in.empty()) {
    *out = "";
    return true;
  }

  std::vector<int> count;
  count.resize(26);
  for (char c : in) {
    count[c - 'a']++;
  }
  std::priority_queue<Letter> q;
  for (int i = 0; i < count.size(); i++) {
    if (count.at(i)) {
      q.push(Letter{'a' + char{i}, count.at(i)});
    }
  }
  std::string output = "";
  output += q.top().c;
  Letter last = q.top();
  q.pop();
  last.count--;

  while (q.top().count) {
    *out += q.top().c;
    Letter tmp = q.top();
    q.pop();
    q.push(last);
    last = tmp;
    last.count--;
  }

  if (q.top().count) {
    return false;
  } else {
    *out = output;
    return true;
  }
}
