#include "strings_and_arrays.h"

#include <unordered_set>
#include <bits/unordered_set.h>
#include <vector>
#include <queue>

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

  while (!q.empty()) {
    output += q.top().c;
    Letter tmp = q.top();
    q.pop();
    if (last.count) {
      q.push(last);
    }
    last = tmp;
    last.count--;
  }

  if (last.count) {
    return false;
  } else {
    *out = output;
    return true;
  }
}


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

int BsRec(const std::vector<int>& v, int start, int stop, int n) {
  if (stop < start) return -1;

  int mid = (start + stop) / 2;

  if (v.at(mid) == n) return mid;
  else if (v.at(mid) > n) {
    return BsRec(v, start, mid - 1, n);
  } else {
    return BsRec(v, mid + 1, stop, n);
  }
}

int BinarySearch(const std::vector<int>& v, int n) {
  return BsRec(v, 0, v.size() - 1, n);
}

int FindPivot(const std::vector<int>& v, int start, int stop) {
  if (start >= stop) return -1;
  if (start + 1 == stop) {
    return v.at(start) > v.at(stop) ? start : -1;
  }
  int mid = (start + stop) / 2;
  if (v.at(mid) > v.at(stop)) {
    return FindPivot(v, mid, stop);
  } else if (v.at(mid) < v.at(start)) {
    return FindPivot(v, start, mid);
  } else {
    // TODO optimize w/ equals to
    int right = FindPivot(v, mid, stop);
    if (right != -1) return right;
    return FindPivot(v, start, mid);
  }
}

int RotBinSearch(const std::vector<int>& v, int n) {
  int pivot = FindPivot(v, 0, v.size() - 1);
  int left = BsRec(v, 0, pivot, n);
  if (left != -1) return left;
  return BsRec(v, pivot + 1, v.size() - 1, n);
}
