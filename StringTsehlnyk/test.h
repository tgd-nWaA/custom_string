// Developed by Bohdan Tsehelnyk in 04.2022
#pragma once
#include <cassert>
#include <iostream>

#define ASSERT(expr) do {                           \
    assert(expr);                                   \
    std::cout << #expr" has passed" << std::endl;   \
} while (false)                                       


#define ASSERT_NOT(expr) ASSERT(!(expr))
#define ASSERT_THROW(expr) do {                 \
    bool isThrow = false;                       \
    try {                                       \
        expr;                                   \
    }                                           \
    catch(...) {                                \
        isThrow = true;                         \
    }                                           \
    ASSERT(isThrow && #expr);                   \
} while (false)

#define ASSERT_EQ(expr1, expr2) do {                                \
    if (expr1 != expr2) {                                           \
        std::cout << #expr1"(with value " << expr1 <<               \
        ") not equal to "#expr2"(with value " << expr2 <<           \
        ")" << std::endl;                                           \
    }                                                               \
    ASSERT(expr1 == expr2);                                         \
} while (false)                                                     \
    