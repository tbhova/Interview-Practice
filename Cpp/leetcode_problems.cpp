#include "leetcode_problems.h"

std::vector<int> twoSum(std::vector<int>& nums, int target) {
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[i] + nums[j] == target) {
        return std::vector<int>{i, j};
      }
    }
  }
  return std::vector<int>();
}

bool IsPalindrome(std::string& s) {
  for (int i = 0; i <= s.size() / 2; ++i) {
    if (s[i] != s[s.size() - 1 - i]) {
      return false;
    }
  }
  return !s.empty();
}

std::string LongestPalindromeSlow(std::string s) {
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j <= i; ++j) {
      std::string ss = s.substr(j, s.size() - i);
      if (IsPalindrome(ss)) {
        return ss;
      }
    }
  }
  return "";
}

std::string LongestPalindrome(std::string s) {
  int start = 0, len = 1;
  for (int i = 0; i < s.size(); ++i) {
    int l = i, r = i;
    while (r < s.size() - 1 && s[r] == s[r + 1]) { ++r; }
    while (l > 0 && r < s.size() - 1 && s[l-1] == s[r+1]) { --l; ++r; }
    if (r - l + 1 > len) {
      len = r - l + 1;
      start = l;
    }
  }
  return s.empty() ? "" : s.substr(start, len);
}

std::string convert(std::string s, int numRows) {
  std::vector<std::string> lines;
  lines.resize(numRows);
  int line_n = 0;
  bool down = true;
  for (int i = 0; i < s.size(); ++i) {
    lines[line_n] += s[i];
    if (numRows == 1) { continue; }
    if (line_n == 0) { down = true; }
    else if (line_n == numRows - 1) { down = false; }
    line_n += down ? 1 : -1;
  }
  std::string r = "";
  for (std::string& line : lines) {
    r += line;
  }
  return r;
}
