#include "gtest/gtest.h"
#include "strings_and_arrays_test.hpp"
#include "linked_lists_test.hpp"
#include "stacks_and_queues_test.hpp"
#include "trees_and_graphs_test.hpp"
#include "recursion_and_dynamic_programming_test.hpp"
#include "leetcode_problems_test.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
