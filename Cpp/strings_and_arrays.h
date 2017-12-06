#ifndef TEST_STRINGS_AND_ARRAYS_H
#define TEST_STRINGS_AND_ARRAYS_H

#include <string>
#include <vector>

using std::string;

bool Permute(const std::string& in, std::string* out);

// Problem 1.1
bool IsUnique(const string& s);

void Reverse(string& in);

int BinarySearch(const std::vector<int>& a, int n);

#endif //TEST_STRINGS_AND_ARRAYS_H
