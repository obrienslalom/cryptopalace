#define GTEST_USE_OWN_TR1_TUPLE 1

#include <iostream>
#include "gtest/gtest.h"

#include "project1.h"

TEST(HexToByte, HexToByteNumbers) {
    for(char i = '0', j = 0; i <= '9'; ++i, ++j)
    {
        EXPECT_EQ(j, HexToByte(i));
    }
}

TEST(HexToByte, HexToByteLowerCaseLetters) {
    for(char i = 'a', j = 10; i <= 'f'; ++i, ++j)
    {
        EXPECT_EQ(j, HexToByte(i));
    }
}

TEST(HexToByte, HexToByteUpperCaseLetters) {
    for(char i = 'A', j = 10; i <= 'F'; ++i, ++j)
    {
        EXPECT_EQ(j, HexToByte(i));
    }
}

TEST(HexToBase64, HexToBase64Stage1Challenge1) {
    ASSERT_STREQ(
        "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t",
        HexToBase64("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d")
    );
    ASSERT_STREQ(
        "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb28=",
        HexToBase64("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f")
    );
}


/*
TEST(XOR, XORStage1Challenge2) {
    ASSERT_STREQ(
        "746865206b696420646f6e277420706c6179",
        XOR("1c0111001f010100061a024b53535009181c", "686974207468652062756c6c277320657965")
    );
}
*/
