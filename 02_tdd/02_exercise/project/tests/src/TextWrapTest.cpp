#include "TextWrap.h"
#include <gtest/gtest.h>

TEST(TextWrap, Constructor) {

    TextWrap textWrap{};
}

TEST(TextWrap, Constructor_PassNumberOfColumnsThroughTheConstructor) {

    TextWrap textWrap{2};
}

TEST(TextWrap, Constructor_ThrowExceptionWhenZeroPassed) {
    EXPECT_THROW(TextWrap textWrap{0}, std::invalid_argument);
}

TEST(TextWrap, Constructor_ThrownExceptionHasValidMessage) {
    try {
        TextWrap textWrap{0};
    }
    catch(std::invalid_argument& invArgExcpt) {
        EXPECT_STREQ("Zero passed as columns.", invArgExcpt.what());
    }
}

TEST(TextWrap, Wrap_OneChraterInOneColumn) {

    TextWrap textWrap{1};

    EXPECT_EQ("a", textWrap.wrap("a"));
}

TEST(TextWrap, Wrap_OneChraterInOneColumn_OtherCharacter) {

    TextWrap textWrap{1};

    EXPECT_EQ("b", textWrap.wrap("b"));
}

TEST(TextWrap, Wrap_TwoChraterInOneColumn) {

    TextWrap textWrap{1};

    EXPECT_EQ("a\nb", textWrap.wrap("ab"));
}

TEST(TextWrap, Wrap_FourChraterInTwoColumn) {

    TextWrap textWrap{2};

    EXPECT_EQ("ab\ncd", textWrap.wrap("abcd"));
}

TEST(TextWrap, Wrap_ThreeCharacterInOneColumn) {
    TextWrap textWrap{1};
    EXPECT_EQ("a\nb\nc", textWrap.wrap("abc"));
}

TEST(TextWrap, Wrap_SpaceToNewLineWhenItsAtLineEnd) {
    TextWrap textWrap{3};
    EXPECT_EQ("ab\ncde", textWrap.wrap("ab cde"));
}

TEST(TextWrap, Wrap_DeleteSpaceWhenItsAtLineBegginning) {
    TextWrap textWrap{4};
    EXPECT_EQ("abcd\nefgh", textWrap.wrap("abcd efgh"));
}

TEST(TextWrap, Wrap_DeleteSpaceWhenItsAtLineBegginningThreeLines) {
    TextWrap textWrap{4};
    EXPECT_EQ("abcd\nefgh\nijkl", textWrap.wrap("abcd efgh ijkl"));
}

TEST(TextWrap, Wrap_LastLineBegginningWithSpace) {
    TextWrap textWrap{3};
    EXPECT_EQ("abc\nde", textWrap.wrap("abc de"));
}

TEST(TextWrap, Wrap_MoveWordExceedingLineToNewLine) {
    TextWrap textWrap{6};
    EXPECT_EQ("abc\ndef\nghij", textWrap.wrap("abc def ghij"));
}

TEST(TextWrap, Wrap_DeleteSpaceAtTextEnd) {
    TextWrap textWrap{4};
    EXPECT_EQ("abc", textWrap.wrap("abc "));
}