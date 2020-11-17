#include <gtest/gtest.h>

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <queue>

TEST(VectorInt, SizeVsCapacity) {

    // TODO: ...

    ASSERT_EQ(3u, vector.size());
    ASSERT_EQ(3u, vector.capacity());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);

    // TODO: ...

    ASSERT_EQ(3u, vector.size());
    ASSERT_EQ(10u, vector.capacity());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);

    // TODO: ...

    ASSERT_EQ(3u, vector.size());
    ASSERT_EQ(3u, vector.capacity());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);

    // TODO: ...

    ASSERT_EQ(4u, vector.size());
    ASSERT_EQ(6u, vector.capacity());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);
    EXPECT_EQ(4, vector[3]);

    // TODO: ...

    ASSERT_EQ(100u, vector.size());
    ASSERT_EQ(100u, vector.capacity());

    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);
    EXPECT_EQ(4, vector[3]);
}

TEST(VectorBool, EraseElement) {

    // TODO: ...

    ASSERT_EQ(3u, vector.size());
    EXPECT_TRUE(vector[0]);
    EXPECT_FALSE(vector[1]);
    EXPECT_TRUE(vector[2]);

    // TODO: ...

    ASSERT_EQ(2u, vector.size());
    EXPECT_TRUE(vector[0]);
    EXPECT_TRUE(vector[1]);
}

TEST(DequeFloat, InsertBeginAndEnd) {

    // TODO: ...

    ASSERT_EQ(0u, deque.size());

    // TODO: ...

    ASSERT_EQ(1u, deque.size());
    EXPECT_FLOAT_EQ(2.0f, deque[0]);

    // TODO: ...

    ASSERT_EQ(3u, deque.size());
    EXPECT_FLOAT_EQ(1.0f, deque[0]);
    EXPECT_FLOAT_EQ(2.0f, deque[1]);
    EXPECT_FLOAT_EQ(3.0f, deque[2]);
}

TEST(VectorFloat, RemoveElementsFromTheEnd) {

    // TODO: ...

    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);

    // TODO: ...

    ASSERT_EQ(1u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);

    // TODO: ...

    ASSERT_EQ(0u, vector.size());
    ASSERT_TRUE(vector.empty());
}

TEST(VectorChar, Copy) {

    // TODO: ...

    ASSERT_EQ(5u, vectorIn.size());
    ASSERT_EQ('a', vectorIn[0]);
    ASSERT_EQ('b', vectorIn[1]);
    ASSERT_EQ('c', vectorIn[2]);
    ASSERT_EQ('d', vectorIn[3]);
    ASSERT_EQ('\0', vectorIn[4]);
    EXPECT_STREQ("abcd", vectorIn.data());

    // TODO: ...

    ASSERT_EQ(5u, vectorIn.size());
    EXPECT_STREQ("abcd", vectorIn.data());
    ASSERT_EQ(5u, vectorOut.size());
    EXPECT_STREQ("abcd", vectorOut.data());
}

TEST(VectorFloat, SizeShouldBeLessThanOrEqualToCapacity) {

    // TODO: ...

    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);
    EXPECT_EQ(vector.capacity(), vector.size());

    // TODO: ...

    ASSERT_EQ(4u, vector.size());
    EXPECT_FLOAT_EQ(4, vector[3]);
    EXPECT_GE(vector.capacity(), vector.size());

    // TODO: ...

    ASSERT_EQ(4u, vector.size());
    EXPECT_EQ(vector.capacity(), vector.size());
}

TEST(VectorFloat, ReserveAdditionalCapacity) {

    // TODO: ...

    EXPECT_EQ(3, vector.size());
    EXPECT_EQ(3, vector.capacity());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);

    // TODO: ...

    EXPECT_EQ(3, vector.size());
    EXPECT_EQ(10, vector.capacity());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);
}

TEST(VectorFloat, RemoveFirstValue) {

    // TODO: ...

    ASSERT_EQ(3u, vector.size());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);

    // TODO: ...

    ASSERT_EQ(2u, vector.size());
    EXPECT_EQ(2, vector[0]);
    EXPECT_EQ(3, vector[1]);
}

TEST(VectorDouble, RemoveLastValue) {

    // TODO: ...

    ASSERT_EQ(3u, vector.size());
    EXPECT_DOUBLE_EQ(1, vector[0]);
    EXPECT_DOUBLE_EQ(2, vector[1]);
    EXPECT_DOUBLE_EQ(3, vector[2]);

    // TODO: ...

    ASSERT_EQ(2u, vector.size());
    EXPECT_DOUBLE_EQ(1, vector[0]);
    EXPECT_DOUBLE_EQ(2, vector[1]);
}

TEST(VectorVectorInt, TwoDimensionalVector) {

    // TODO: ...

    EXPECT_FLOAT_EQ(1, vector[0][0]);
    EXPECT_FLOAT_EQ(2, vector[0][1]);
    EXPECT_FLOAT_EQ(3, vector[0][2]);
    EXPECT_FLOAT_EQ(4, vector[1][0]);
    EXPECT_FLOAT_EQ(5, vector[1][1]);
    EXPECT_FLOAT_EQ(6, vector[1][2]);
}

TEST(VectorFloat, SortLargeVector) {

    // TODO: ...

    EXPECT_EQ(1000, vector.size());
    ASSERT_FALSE(std::is_sorted(vector.begin(), vector.end()));

    // TODO: ...

    EXPECT_EQ(1000, vector.size());
    EXPECT_TRUE(std::is_sorted(vector.begin(), vector.end()));
}

TEST(ArrayInt, HasConstantSizeDefinedAtCompileTime) {

    // TODO: ...

    static_assert(array.size() == 2, "Compilation error: wrong array size");

    ASSERT_EQ(1u, array[0]);
    ASSERT_EQ(2u, array[1]);
}

TEST(ArrayArrayArrayInt, ThreeDimensionalStaticArray) {

    // TODO: ...

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

    // TODO: ...

    ASSERT_EQ(5, list.size());
    auto listIterator = list.begin();
    EXPECT_EQ(5, *(listIterator++));
    EXPECT_EQ(6, *(listIterator++));
    EXPECT_EQ(7, *(listIterator++));
    EXPECT_EQ(8, *(listIterator++));
    EXPECT_EQ(9, *(listIterator++));

    // TODO: ...

    ASSERT_EQ(2, list.size());
    EXPECT_EQ(5, list.front());
    EXPECT_EQ(6, list.back());
}

TEST(ListInt, UniqueNextToEachOther) {

    // TODO: ...

    EXPECT_EQ(6, list.size());
    auto listIterator = list.begin();
    EXPECT_EQ(1, *(listIterator++));
    EXPECT_EQ(2, *(listIterator++));
    EXPECT_EQ(1, *(listIterator++));
    EXPECT_EQ(1, *(listIterator++));
    EXPECT_EQ(2, *(listIterator++));
    EXPECT_EQ(2, *(listIterator++));
    EXPECT_EQ(list.end(), listIterator);

    // TODO: ...

    EXPECT_EQ(4, list.size());
    listIterator = list.begin();
    EXPECT_EQ(1, *(listIterator++));
    EXPECT_EQ(2, *(listIterator++));
    EXPECT_EQ(1, *(listIterator++));
    EXPECT_EQ(2, *(listIterator++));
    EXPECT_EQ(list.end(), listIterator);
}

TEST(DequeInt, PopFrontValue) {

    // TODO: ...

    ASSERT_EQ(3u, deque.size());
    EXPECT_FLOAT_EQ(1, deque[0]);
    EXPECT_FLOAT_EQ(2, deque[1]);
    EXPECT_FLOAT_EQ(3, deque[2]);

    // TODO: ...

    ASSERT_EQ(2u, deque.size());
    EXPECT_FLOAT_EQ(2, deque[0]);
    EXPECT_FLOAT_EQ(3, deque[1]);
}

TEST(QueueDouble, PushAndPop) {

    // TODO: ...

    EXPECT_TRUE(queue.empty());

    // TODO: ...

    ASSERT_EQ(4u, queue.size());
    EXPECT_DOUBLE_EQ(1.0, queue.front());
    EXPECT_DOUBLE_EQ(4.0, queue.back());

    // TODO: ...

    ASSERT_EQ(3u, queue.size());
    EXPECT_DOUBLE_EQ(2.0, queue.front());
    EXPECT_DOUBLE_EQ(4.0, queue.back());

    // TODO: ...

    ASSERT_EQ(2u, queue.size());
    EXPECT_DOUBLE_EQ(3.0, queue.front());
    EXPECT_DOUBLE_EQ(4.0, queue.back());

    // TODO: ...

    ASSERT_EQ(1u, queue.size());
    EXPECT_DOUBLE_EQ(4.0, queue.front());
    EXPECT_DOUBLE_EQ(4.0, queue.back());

    // TODO: ...

    ASSERT_EQ(0u, queue.size());
}
