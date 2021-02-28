cmake_minimum_required(VERSION 3.14)
#project(leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        inc
        src
        test
        /usr/local/include
        /Library/Developer/CommandLineTools/usr/include/c++/v1/
        /usr/include)

set(SRC )

set(TEST    test/test_sort_string.cpp
            test/test_002.cpp
            test/test_003.cpp
            test/test_004.cpp
            test/test_005.cpp
            test/test_006.cpp
            test/test_007.cpp
            test/test_008.cpp
            test/test_009.cpp
            test/test_010.cpp
            test/test_011.cpp
            test/test_085.cpp
        test/test_547.cpp
        test/test_1564.cpp
        test/test_1713.cpp
        )


add_executable(leetcode main.cpp  ${TEST} )

link_directories(/usr/local/lib)

target_link_libraries(leetcode gtest)