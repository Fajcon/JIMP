//
// Created by mwypych on 01.06.17.
//
#ifndef ARABIC_TO_ROMAN_TEST_H_
#define ARABIC_TO_ROMAN_TEST_H_

#include <gtest/gtest.h>
#include <ArabicRoman.h>

TEST(ArabicToRoman, ConvertionOfArabicNumberZeroToRomanReturnsError){
    EXPECT_THROW(ArabicToRoman(0), std::invalid_argument);
}
TEST(ArabicToRoman, ConvertionOfArabicMinusNumberToRomanReturnsError){
    EXPECT_THROW(ArabicToRoman(-12), std::invalid_argument);
}
TEST(ArabicToRoman, ConvertionOfArabicNumberBiggerThan3999ToRomanReturnsError){
    EXPECT_THROW(ArabicToRoman(5000), std::invalid_argument);
}
TEST(ArabicToRoman, ConvertionOfArabicNumberOneToRomanReturnsI){
    EXPECT_EQ("I", ArabicToRoman(1));
}
TEST(ArabicToRoman, ConvertionOfArabicNumberTwoToRomanReturnsII){
    EXPECT_EQ("II", ArabicToRoman(2));
}
TEST(ArabicToRoman, ConvertionOfArabicNumber4ToRomanReturnsIV){
    EXPECT_EQ("IV", ArabicToRoman(4));
}
TEST(ArabicToRoman, ConvertionOfArabicNumber100ToRomanReturnsC){
    EXPECT_EQ("C", ArabicToRoman(100));
}
TEST(ArabicToRoman, ConvertionOfArabicNumber3999ToRomanReturnsMMMCMXCIX){
    EXPECT_EQ("MMMCMXCIX", ArabicToRoman(3999));
}

TEST(RomanToArabic, RomanContainsWrongSignsReturnsError){
    EXPECT_THROW(RomanToArabic("U"), std::invalid_argument);
}

#endif
