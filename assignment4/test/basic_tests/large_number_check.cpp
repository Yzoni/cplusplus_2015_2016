//
// Yorick de Boer (10786015)
//

#include <gtest/gtest.h>

#include "LargeNumber.h"


/*
 * PLUS PLUS
 */
TEST(large_number_check__Test, plusplus) {
    LargeNumber *plus1 = new LargeNumber("2");
    (*plus1)++;
    stringstream ss;
    ss << plus1;

    EXPECT_EQ(ss.str(), "3");
}

TEST(large_number_check__Test, plusplus2) {
    LargeNumber *plus1 = new LargeNumber("9999");
    (*plus1)++;
    stringstream ss;
    ss << plus1;

    EXPECT_EQ(ss.str(), "10000");
}

TEST(large_number_check__Test, plusplus3) {
    LargeNumber *plus1 = new LargeNumber("99999");
    (*plus1)++;
    stringstream ss;
    ss << plus1;

    EXPECT_EQ(ss.str(), "100000");
}


/*
 * PLUS
 */
TEST(large_number_check__Test, plus) {
    LargeNumber *plus1 = new LargeNumber("2");
    LargeNumber *plus2 = new LargeNumber("50");
    stringstream ss;
    ss << (*plus1) + plus2;

    EXPECT_EQ(ss.str(), "52");
}

TEST(large_number_check__Test, plus1) {
    LargeNumber *plus1 = new LargeNumber("9999");
    LargeNumber *plus2 = new LargeNumber("9999");
    stringstream ss;
    ss << (*plus1) + plus2;

    EXPECT_EQ(ss.str(), "19998");
}

TEST(large_number_check__Test, plus2) {
    LargeNumber *plus1 = new LargeNumber("9239043094");
    LargeNumber *plus2 = new LargeNumber("324039490328");
    stringstream ss;
    ss << (*plus1) + plus2;

    EXPECT_EQ(ss.str(), "333278533422");
}


/*
 * MULTIPLY
 */
TEST(large_number_check__Test, multiply_single_no_overflow) {
    LargeNumber *plus1 = new LargeNumber("2");
    LargeNumber *plus2 = new LargeNumber("953");
    stringstream ss;
    ss << (*plus1) * plus2;

    EXPECT_EQ(ss.str(), "1906");
}

TEST(large_number_check__Test, multiply_single_overflow) {
    LargeNumber *plus1 = new LargeNumber("293");
    LargeNumber *plus2 = new LargeNumber("9999");
    stringstream ss;
    ss << (*plus1) * plus2;

    EXPECT_EQ(ss.str(), "2929707");
}

TEST(large_number_check__Test, multiply_single_inverse) {
    LargeNumber *plus1 = new LargeNumber("9999");
    LargeNumber *plus2 = new LargeNumber("293");
    stringstream ss;
    ss << (*plus1) * plus2;

    EXPECT_EQ(ss.str(), "2929707");
}


TEST(large_number_check__Test, multiply_multiple_overflow) {
    LargeNumber *plus1 = new LargeNumber("9320480923849230483094823");
    LargeNumber *plus2 = new LargeNumber("2348230948309234234");
    stringstream ss;
    ss << (*plus1) * plus2;

    EXPECT_EQ(ss.str(), "21886641758508606085386383307111481539770582");
}