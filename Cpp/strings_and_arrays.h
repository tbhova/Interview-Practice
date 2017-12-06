#ifndef TEST_STRINGS_AND_ARRAYS_H
#define TEST_STRINGS_AND_ARRAYS_H

#include <string>
#include <vector>

using std::string;

bool Permute(const std::string& in, std::string* out);

// Problem 1.1
bool IsUnique(const string& s);

void Reverse(string& in);

// return index of element with n, vector v is sorted.
int BinarySearch(const std::vector<int>& v, int n);

// return index of element with value n. v is sorted but rotated.
int RotBinSearch(const std::vector<int>& v, int n);

#endif //TEST_STRINGS_AND_ARRAYS_H
