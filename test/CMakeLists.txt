CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

PROJECT(test_bitter)

ADD_EXECUTABLE(
    test_bitter
    source/test_bitter_main.cpp
    source/test_bitter_read.cpp
    source/test_bitter_write.cpp
    source/test_bitter_variable_unsigned_integer.cpp
)

INCLUDE_DIRECTORIES(
    test_bitter
    dependencies/Catch/single_include
    ../include
)

TARGET_LINK_LIBRARIES(
    test_bitter
    gcov asan
)

TARGET_COMPILE_FEATURES(
    test_bitter
    PRIVATE
    cxx_relaxed_constexpr
)

SET_PROPERTY(
    TARGET test_bitter 
    APPEND_STRING PROPERTY COMPILE_FLAGS
    "-Wall -Werror -fsanitize=address --coverage"
)

