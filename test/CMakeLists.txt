CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(test_bitter)

ADD_EXECUTABLE(
    test_bitter
    source/test_bitter_main.cpp
    source/test_bitter_read.cpp
    source/test_bitter_write.cpp
)

INCLUDE_DIRECTORIES(
    test_bitter
    dependencies/Catch/single_include
    ../include
)

TARGET_COMPILE_FEATURES(
    test_bitter
    PRIVATE
    cxx_relaxed_constexpr
)

