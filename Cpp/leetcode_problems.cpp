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

std::string LongestPalindrome(std::string s) {
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
