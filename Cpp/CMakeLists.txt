cmake_minimum_required(VERSION 3.8)
project(iterview-practice)

set(CMAKE_CXX_STANDARD 17)

project(test)

include(CTest)
enable_testing()

set(REPO ${CMAKE_CURRENT_SOURCE_DIR})

#set(gtest_disable_pthreads on) #needed in MinGW
include(${REPO}/DownloadProject/DownloadProject.cmake)

download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
)

set(test_SOURCES
        g_test_main.cpp strings_and_arrays.cpp linked_lists.cpp stacks_and_queues.cpp trees_and_graphs.cpp sorting_and_searching.cpp leetcode_problems.cpp)

set(test_HEADERS
        strings_and_arrays_test.hpp strings_and_arrays.h linked_lists.h linked_lists_test.hpp stacks_and_queues.h stacks_and_queues_test.hpp trees_and_graphs.h trees_and_graphs_test.hpp recursion_and_dynamic_programming.h recursion_and_dynamic_programming.cpp recursion_and_dynamic_programming_test.hpp sorting_and_searching.h sorting_and_searching_test.hpp leetcode_problems.h leetcode_problems_test.hpp)

set(CMAKE_PREFIX_PATH
        ${CMAKE_PREFIX_PATH})

add_executable(UnitTests ${test_SOURCES} ${test_HEADERS})

target_link_libraries(UnitTests gtest gmock ${PROTOBUF_LIBRARIES})

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
