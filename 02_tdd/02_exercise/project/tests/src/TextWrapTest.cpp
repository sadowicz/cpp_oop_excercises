#include "TextWrap.h"
#include <gtest/gtest.h>

class TextWrapTest : public ::testing::Test {
public:

    void SetUp() override {
        Test::SetUp();
    }

    void TearDown() override {
        Test::TearDown();
    }

    TextWrap textWrap{};
};

// test fixture

TEST_F(TextWrapTest, Foo) {

    textWrap.wrap("a");
}

TEST(TextWrap, Constructor) {

    TextWrap textWrap{};
}

TEST(TextWrap, Constructor_PassNumberOfColumnsThroughTheConstructor) {

    TextWrap textWrap{2};
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