#include <gtest/gtest.h>
#include "../src/hola.cpp"

namespace{
    Hola f;
    TEST(FactorialTest, Negative){
        EXPECT_EQ(1, f.factorial(-5));
    }
}