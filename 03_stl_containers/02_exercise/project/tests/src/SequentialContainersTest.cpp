#include <gtest/gtest.h>

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <queue>

TEST(VectorInt, SizeVsCapacity) {

    std::vector<int> vector = {1, 2, 3};

    ASSERT_EQ(3u, vector.size());
    ASSERT_EQ(3u, vector.capacity());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);

    vector.reserve(10);

    ASSERT_EQ(3u, vector.size());
    ASSERT_EQ(10u, vector.capacity());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);

    vector.shrink_to_fit();

    ASSERT_EQ(3u, vector.size());
    ASSERT_EQ(3u, vector.capacity());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);

    vector.push_back(4);

    ASSERT_EQ(4u, vector.size());
    ASSERT_EQ(6u, vector.capacity());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);
    EXPECT_EQ(4, vector[3]);

    vector.resize(100);

    ASSERT_EQ(100u, vector.size());
    ASSERT_EQ(100u, vector.capacity());

    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);
    EXPECT_EQ(4, vector[3]);
}

TEST(VectorBool, EraseElement) {

    std::vector<bool> vector{true, false, true};

    ASSERT_EQ(3u, vector.size());
    EXPECT_TRUE(vector[0]);
    EXPECT_FALSE(vector[1]);
    EXPECT_TRUE(vector[2]);

    vector.erase(vector.begin() + 1);

    ASSERT_EQ(2u, vector.size());
    EXPECT_TRUE(vector[0]);
    EXPECT_TRUE(vector[1]);
}

TEST(DequeFloat, InsertBeginAndEnd) {

    std::deque<float> deque{};

    ASSERT_EQ(0u, deque.size());

    deque.push_back(2.f);

    ASSERT_EQ(1u, deque.size());
    EXPECT_FLOAT_EQ(2.0f, deque[0]);

    deque.push_front(1.f);
    deque.push_back(3.f);

    ASSERT_EQ(3u, deque.size());
    EXPECT_FLOAT_EQ(1.0f, deque[0]);
    EXPECT_FLOAT_EQ(2.0f, deque[1]);
    EXPECT_FLOAT_EQ(3.0f, deque[2]);
}

TEST(VectorFloat, RemoveElementsFromTheEnd) {

    std::vector<float> vector{1.f, 2.f, 3.f};

    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);

    vector.pop_back();
    vector.pop_back();

    ASSERT_EQ(1u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);

    vector.clear();

    ASSERT_EQ(0u, vector.size());
    ASSERT_TRUE(vector.empty());
}

TEST(VectorChar, Copy) {

    std::vector<char> vectorIn{'a', 'b', 'c', 'd', '\0'};

    ASSERT_EQ(5u, vectorIn.size());
    ASSERT_EQ('a', vectorIn[0]);
    ASSERT_EQ('b', vectorIn[1]);
    ASSERT_EQ('c', vectorIn[2]);
    ASSERT_EQ('d', vectorIn[3]);
    ASSERT_EQ('\0', vectorIn[4]);
    EXPECT_STREQ("abcd", vectorIn.data());

    std::vector<char> vectorOut = vectorIn;

    ASSERT_EQ(5u, vectorIn.size());
    EXPECT_STREQ("abcd", vectorIn.data());
    ASSERT_EQ(5u, vectorOut.size());
    EXPECT_STREQ("abcd", vectorOut.data());
}

TEST(VectorFloat, SizeShouldBeLessThanOrEqualToCapacity) {

    std::vector<float> vector{1.f, 2.f, 3.f};

    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);
    EXPECT_EQ(vector.capacity(), vector.size());

    vector.push_back(4.f);

    ASSERT_EQ(4u, vector.size());
    EXPECT_FLOAT_EQ(4, vector[3]);
    EXPECT_GE(vector.capacity(), vector.size());

    vector.shrink_to_fit();

    ASSERT_EQ(4u, vector.size());
    EXPECT_EQ(vector.capacity(), vector.size());
}

TEST(VectorFloat, ReserveAdditionalCapacity) {

    std::vector<float> vector{1.f, 2.f, 3.f};

    EXPECT_EQ(3, vector.size());
    EXPECT_EQ(3, vector.capacity());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);

    vector.reserve(10);

    EXPECT_EQ(3, vector.size());
    EXPECT_EQ(10, vector.capacity());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);
}

TEST(VectorFloat, RemoveFirstValue) {

    std::vector<float> vector{1.f, 2.f, 3.f};

    ASSERT_EQ(3u, vector.size());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);

    vector.erase(vector.begin());

    ASSERT_EQ(2u, vector.size());
    EXPECT_EQ(2, vector[0]);
    EXPECT_EQ(3, vector[1]);
}

TEST(VectorDouble, RemoveLastValue) {

    std::vector<double> vector{1.0, 2.0, 3.0};

    ASSERT_EQ(3u, vector.size());
    EXPECT_DOUBLE_EQ(1, vector[0]);
    EXPECT_DOUBLE_EQ(2, vector[1]);
    EXPECT_DOUBLE_EQ(3, vector[2]);

    vector.pop_back();

    ASSERT_EQ(2u, vector.size());
    EXPECT_DOUBLE_EQ(1, vector[0]);
    EXPECT_DOUBLE_EQ(2, vector[1]);
}

TEST(VectorVectorInt, TwoDimensionalVector) {

    std::vector<std::vector<int>> vector{{1, 2, 3}, {4, 5, 6}};

    EXPECT_FLOAT_EQ(1, vector[0][0]);
    EXPECT_FLOAT_EQ(2, vector[0][1]);
    EXPECT_FLOAT_EQ(3, vector[0][2]);
    EXPECT_FLOAT_EQ(4, vector[1][0]);
    EXPECT_FLOAT_EQ(5, vector[1][1]);
    EXPECT_FLOAT_EQ(6, vector[1][2]);
}

TEST(VectorFloat, SortLargeVector) {

    std::vector<float> vector{};
    vector.resize(1000);
    vector[744] = 49.f;

    EXPECT_EQ(1000, vector.size());
    ASSERT_FALSE(std::is_sorted(vector.begin(), vector.end()));

    std::sort(vector.begin(), vector.end());

    EXPECT_EQ(1000, vector.size());
    EXPECT_TRUE(std::is_sorted(vector.begin(), vector.end()));
}

TEST(ArrayInt, HasConstantSizeDefinedAtCompileTime) {

    std::array<int, 2> array{1, 2};

    static_assert(array.size() == 2, "Compilation error: wrong array size");

    ASSERT_EQ(1u, array[0]);
    ASSERT_EQ(2u, array[1]);
}

TEST(ArrayArrayArrayInt, ThreeDimensionalStaticArray) {

    std::array<std::array<std::array<int, 2>, 2>, 2> array{{{{{1, 2}, {3, 4}}}, {{{5, 6}, {7, 8}}}}};

    ASSERT_EQ(2u, array.size());
    ASSERT_EQ(2u, array[0].size());
    ASSERT_EQ(2u, array[1].size());
    ASSERT_EQ(2u, array[0][0].size());
    ASSERT_EQ(2u, array[0][1].size());
    ASSERT_EQ(2u, array[1][0].size());
    ASSERT_EQ(2u, array[1][1].size());

    EXPECT_EQ(1, array[0][0][0]);
    EXPECT_EQ(2, array[0][0][1]);
    EXPECT_EQ(3, array[0][1][0]);
    EXPECT_EQ(4, array[0][1][1]);
    EXPECT_EQ(5, array[1][0][0]);
    EXPECT_EQ(6, array[1][0][1]);
    EXPECT_EQ(7, array[1][1][0]);
    EXPECT_EQ(8, array[1][1][1]);
}

TEST(ListInt, RemoveIfGreaterOrEqualToSeven) {

    std::list<int> list{5, 6, 7, 8, 9};

    ASSERT_EQ(5, list.size());
    auto listIterator = list.begin();
    EXPECT_EQ(5, *(listIterator++));
    EXPECT_EQ(6, *(listIterator++));
    EXPECT_EQ(7, *(listIterator++));
    EXPECT_EQ(8, *(listIterator++));
    EXPECT_EQ(9, *(listIterator++));

    list.remove_if([](int el){ return el >= 7; });

    ASSERT_EQ(2, list.size());
    EXPECT_EQ(5, list.front());
    EXPECT_EQ(6, list.back());
}

TEST(ListInt, UniqueNextToEachOther) {

    std::list<int> list{1, 2, 1, 1, 2, 2};

    EXPECT_EQ(6, list.size());
    auto listIterator = list.begin();
    EXPECT_EQ(1, *(listIterator++));
    EXPECT_EQ(2, *(listIterator++));
    EXPECT_EQ(1, *(listIterator++));
    EXPECT_EQ(1, *(listIterator++));
    EXPECT_EQ(2, *(listIterator++));
    EXPECT_EQ(2, *(listIterator++));
    EXPECT_EQ(list.end(), listIterator);

    list.unique();

    EXPECT_EQ(4, list.size());
    listIterator = list.begin();
    EXPECT_EQ(1, *(listIterator++));
    EXPECT_EQ(2, *(listIterator++));
    EXPECT_EQ(1, *(listIterator++));
    EXPECT_EQ(2, *(listIterator++));
    EXPECT_EQ(list.end(), listIterator);
}

TEST(DequeInt, PopFrontValue) {

    std::deque<int> deque{1, 2, 3};

    ASSERT_EQ(3u, deque.size());
    EXPECT_FLOAT_EQ(1, deque[0]);
    EXPECT_FLOAT_EQ(2, deque[1]);
    EXPECT_FLOAT_EQ(3, deque[2]);

    deque.pop_front();

    ASSERT_EQ(2u, deque.size());
    EXPECT_FLOAT_EQ(2, deque[0]);
    EXPECT_FLOAT_EQ(3, deque[1]);
}

TEST(QueueDouble, PushAndPop) {

    std::queue<double> queue{};

    EXPECT_TRUE(queue.empty());

    queue.push(1.0);
    queue.push(2.0);
    queue.push(3.0);
    queue.push(4.0);

    ASSERT_EQ(4u, queue.size());
    EXPECT_DOUBLE_EQ(1.0, queue.front());
    EXPECT_DOUBLE_EQ(4.0, queue.back());

    queue.pop();

    ASSERT_EQ(3u, queue.size());
    EXPECT_DOUBLE_EQ(2.0, queue.front());
    EXPECT_DOUBLE_EQ(4.0, queue.back());

    queue.pop();

    ASSERT_EQ(2u, queue.size());
    EXPECT_DOUBLE_EQ(3.0, queue.front());
    EXPECT_DOUBLE_EQ(4.0, queue.back());

    queue.pop();

    ASSERT_EQ(1u, queue.size());
    EXPECT_DOUBLE_EQ(4.0, queue.front());
    EXPECT_DOUBLE_EQ(4.0, queue.back());

    queue.pop();

    ASSERT_EQ(0u, queue.size());
}