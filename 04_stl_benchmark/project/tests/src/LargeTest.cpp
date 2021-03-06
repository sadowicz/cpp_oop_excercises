#include "TestIncludes.h"

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "Large.h"

TEST(LargeTest, SizeIsOneMegabyte) {

    EXPECT_EQ(1024u*1024u, sizeof(Large));
}

TEST(LargeTest, CreateObject) {

    Large large{};
}

TEST(LargeTest, HasLessThenOperator) {

    Large a{};
    Large b{};

    a < b;
}

TEST(LargeTest, LessThanOperatorReturnsTrueWhenLeftArgData0IsLessThanRightArgData0) {
    Large a{};
    Large b{};

    std::fill_n(a.data, Large::SIZE, 5);
    std::fill_n(b.data, Large::SIZE, 5);

    a.data[0] = 3;

    EXPECT_EQ(true, a < b);
}

TEST(LargeTest, LessThanOperatorReturnsFalseWhenLeftArgData0IsGreaterThanRightArgData0) {
    Large a{};
    Large b{};

    std::fill_n(a.data, Large::SIZE, 5);
    std::fill_n(b.data, Large::SIZE, 5);

    a.data[0] = 6;

    EXPECT_EQ(false, a < b);
}

TEST(LargeTest, LessThanOperatorReturnsFalseWhenLeftArgDataIsSameAsRightArgData) {
    Large a{};
    Large b{};

    std::fill_n(a.data, Large::SIZE, 2);
    std::fill_n(b.data, Large::SIZE, 2);

    EXPECT_EQ(false, a < b);
}

TEST(LargeTest, LessThanOperatorReturnsTrueWhenEncounteredLeftArgDataElementLessThanRightArgDataElementAfterEqualElements) {
    Large a{};
    Large b{};

    std::fill_n(a.data, Large::SIZE, 2);
    std::fill_n(b.data, Large::SIZE, 2);

    a.data[100] = 1;

    EXPECT_EQ(true, a < b);
}
TEST(LargeTest, HasEqualityOperator) {

    Large a{};
    Large b{};

    a == b;
}

TEST(LargeTest, EqualityOperatorReturnsFalseWhenLeftArgData0IsLessThanRightArgData0) {

    Large a{};
    Large b{};

    std::fill_n(a.data, Large::SIZE, 4);
    std::fill_n(b.data, Large::SIZE, 4);

    a.data[0] = 2;

    EXPECT_EQ(false, a == b);
}

TEST(LargeTest, EqualityOperatorReturnsTrueWhenLeftArgDataIsSameAsRightArgData) {

    Large a{};
    Large b{};

    std::fill_n(a.data, Large::SIZE, 4);
    std::fill_n(b.data, Large::SIZE, 4);

    EXPECT_EQ(true, a == b);
}

TEST(LargeTest, EqualityOperatorReturnsFalseWhenLeftArgData0IsGreaterThanRightArgData0) {

    Large a{};
    Large b{};

    std::fill_n(a.data, Large::SIZE, 3);
    std::fill_n(b.data, Large::SIZE, 3);

    a.data[0] = 4;

    EXPECT_EQ(false, a == b);
}

TEST(LargeTest, EqualityOperatorReturnsFalseWhenEncounteredLeftArgDataElementUnequalToRightArgDataElementAfterEqualElements) {

    Large a{};
    Large b{};
    Large c{};

    std::fill_n(a.data, Large::SIZE, 3);
    std::fill_n(b.data, Large::SIZE, 3);
    std::fill_n(c.data, Large::SIZE, 3);

    a.data[200] = 2;
    b.data[120] = 4;

    EXPECT_EQ(false, a == c);
    EXPECT_EQ(false, b == c);
}


TEST(LargeTest, CanBeHashed) {

    Large large{};
    std::hash<Large> hash;

    hash(large);
}

TEST(LargeTest, HashIsSameForArgsWithIdenticallyFilledDataArray) {

Large a{};
Large b{};

std::fill_n(a.data, Large::SIZE, 241099.443403);
std::fill_n(b.data, Large::SIZE, 241099.443403);

EXPECT_EQ(std::hash<Large>{}(a), std::hash<Large>{}(b));
}

TEST(LargeTest, Collections) {

    Large large{};

    std::vector<Large> vector{};
    vector.push_back(large);

    std::array<Large, 1> array{};
    array[0] = large;

    std::deque<Large> deque{};
    deque.push_back(large);

    std::list<Large> list{};
    list.push_back(large);

    std::forward_list<Large> forward_list{};
    forward_list.push_front(large);

    std::map<Large, bool> map{};
    map[large] = true;

    std::set<Large> set{};
    set.insert(large);

    std::unordered_map<Large, bool> unordered_map{};
    unordered_map[large] = true;

    std::unordered_set<Large> unordered_set{};
    unordered_set.insert(large);
}

TEST(LargeTest, Randomize) {

    Large large{};
    large.randomize();

    auto count = 0u;

    for (double i : large.data) {

        ASSERT_LE(0.0, i);
        ASSERT_GE(1.0, i);

        if (i != 0.0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(LargeTest, Clear) {

    Large large{};
    large.randomize();
    large.clear();

    for (double i : large.data) {
        ASSERT_DOUBLE_EQ(0.0, i);
    }
}


// TODO: Add tests for your operators implementation!