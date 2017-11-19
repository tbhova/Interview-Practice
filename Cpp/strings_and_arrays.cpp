#include "strings_and_arrays.h"

#include <unordered_set>
#include <bits/unordered_set.h>


bool IsUnique(const string &s) {
  std::unordered_set<char> seen;
  for (const char& c : s) {
    if (seen.find(c) != seen.end()) {
      return false;
    }
    seen.insert(c);
  }
  return true;
}

void Reverse(string& in) {
  unsigned int end = in.size();
  if (end == 0) { return; }
  end--;
  for (int i = 0; i < end; i++, end--) {
    char tmp = in[i];
    in[i] = in[end];
    in[end] = tmp;
  }
}

