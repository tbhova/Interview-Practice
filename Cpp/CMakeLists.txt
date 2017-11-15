cmake_minimum_required(VERSION 3.8)
project(Cpp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(Cpp ${SOURCE_FILES})

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
        UPDATE_DISCONNECTED 1
)

set(test_SOURCES
        g_test_main.cpp)

set(test_HEADERS
        test.hpp)

set(CMAKE_PREFIX_PATH
        ${CMAKE_PREFIX_PATH}
        ${THIRDPARTY_DIR}/protobuf-2.6.1
        )

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

add_executable(UnitTests ${test_SOURCES} ${test_HEADERS})

target_link_libraries(UnitTests gtest gmock ${PROTOBUF_LIBRARIES})

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
