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

#include "Medium.h"

TEST(MediumTest, SizeIsOneKiloByte) {

    EXPECT_EQ(1024u, sizeof(Medium));
}

TEST(MediumTest, CreateObject) {

    Medium medium{};
}

TEST(MediumTest, HasLessThenOperator) {

    Medium a{};
    Medium b{};
    a < b;
}

TEST(MediumTest, LessThanOperatorReturnsTrueWhenLeftArgData0IsLessThanRightArgData0) {
    Medium a{};
    Medium b{};

    std::fill_n(a.data, Medium::SIZE, 5);
    std::fill_n(b.data, Medium::SIZE, 5);

    a.data[0] = 3;

    EXPECT_EQ(true, a < b);
}

TEST(MediumTest, LessThanOperatorReturnsFalseWhenLeftArgData0IsGreaterThanRightArgData0) {
    Medium a{};
    Medium b{};

    std::fill_n(a.data, Medium::SIZE, 5);
    std::fill_n(b.data, Medium::SIZE, 5);

    a.data[0] = 6;

    EXPECT_EQ(false, a < b);
}

TEST(MediumTest, LessThanOperatorReturnsFalseWhenLeftArgDataIsSameAsRightArgData) {
    Medium a{};
    Medium b{};

    std::fill_n(a.data, Medium::SIZE, 2);
    std::fill_n(b.data, Medium::SIZE, 2);

    EXPECT_EQ(false, a < b);
}

TEST(MediumTest, LessThanOperatorReturnsTrueWhenEncounteredLeftArgDataElementLessThanRightArgDataElementAfterEqualElements) {
    Medium a{};
    Medium b{};

    std::fill_n(a.data, Medium::SIZE, 2);
    std::fill_n(b.data, Medium::SIZE, 2);

    a.data[100] = 1;

    EXPECT_EQ(true, a < b);
}

TEST(MediumTest, HasEqualityOperator) {

    Medium a{};
    Medium b{};
    a == b;
}

TEST(MediumTest, EqualityOperatorReturnsFalseWhenLeftArgData0IsLessThanRightArgData0) {

    Medium a{};
    Medium b{};

    std::fill_n(a.data, Medium::SIZE, 4);
    std::fill_n(b.data, Medium::SIZE, 4);

    a.data[0] = 2;

    EXPECT_EQ(false, a == b);
}

TEST(MediumTest, EqualityOperatorReturnsTrueWhenLeftArgDataIsSameAsRightArgData) {

Medium a{};
Medium b{};

std::fill_n(a.data, Medium::SIZE, 4);
std::fill_n(b.data, Medium::SIZE, 4);

EXPECT_EQ(true, a == b);
}

TEST(MediumTest, EqualityOperatorReturnsFalseWhenLeftArgData0IsGreaterThanRightArgData0) {

    Medium a{};
    Medium b{};

    std::fill_n(a.data, Medium::SIZE, 3);
    std::fill_n(b.data, Medium::SIZE, 3);

    a.data[0] = 4;

    EXPECT_EQ(false, a == b);
}

TEST(MediumTest, EqualityOperatorReturnsFalseWhenEncounteredLeftArgDataElementUnequalToRightArgDataElementAfterEqualElements) {

    Medium a{};
    Medium b{};
    Medium c{};

    std::fill_n(a.data, Medium::SIZE, 3);
    std::fill_n(b.data, Medium::SIZE, 3);
    std::fill_n(c.data, Medium::SIZE, 3);

    a.data[200] = 2;
    b.data[120] = 4;

    EXPECT_EQ(false, a == c);
    EXPECT_EQ(false, b == c);
}

TEST(MediumTest, CanBeHashed) {

    Medium medium{};
    std::hash<Medium> hash;
    hash(medium);
}

TEST(MediumTest, HashIsSameForArgsWithIdenticallyFilledDataArray) {

    Medium a{};
    Medium b{};

    std::fill_n(a.data, Medium::SIZE, 4);
    std::fill_n(b.data, Medium::SIZE, 4);

    EXPECT_EQ(std::hash<Medium>{}(a), std::hash<Medium>{}(b));
}

TEST(MediumTest, Collections) {

    Medium medium{};

    std::vector<Medium> vector{};
    vector.push_back(medium);

    std::array<Medium, 1> array{};
    array[0] = medium;

    std::deque<Medium> deque{};
    deque.push_back(medium);

    std::list<Medium> list{};
    list.push_back(medium);

    std::forward_list<Medium> forward_list{};
    forward_list.push_front(medium);

    std::map<Medium, bool> map{};
    map[medium] = true;

    std::set<Medium> set{};
    set.insert(medium);

    std::unordered_map<Medium, bool> unordered_map{};
    unordered_map[medium] = true;

    std::unordered_set<Medium> unordered_set{};
    unordered_set.insert(medium);
}


TEST(MediumTest, Randomize) {

    Medium medium{};
    medium.randomize();

    auto count = 0u;

    for (int i : medium.data) {
        ASSERT_LE(0, i);
        ASSERT_GE(std::numeric_limits<int>::max(), i);

        if (i != 0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(MediumTest, Clear) {

    Medium medium{};
    medium.randomize();
    medium.clear();

    for (int i : medium.data) {
        ASSERT_EQ(0, i);
    }
}