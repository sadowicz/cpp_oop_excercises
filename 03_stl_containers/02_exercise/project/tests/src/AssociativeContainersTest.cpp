#include <gtest/gtest.h>

#include <set>
#include <map>
#include <unordered_set>

TEST(SetString, RemoveElements) {

    // TODO: ...

    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count("A"));
    EXPECT_EQ(1u, set.count("B"));
    EXPECT_EQ(1u, set.count("C"));

    // TODO: ...

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count("A"));
    EXPECT_EQ(0u, set.count("B"));
    EXPECT_EQ(1u, set.count("C"));
}

TEST(SetFloat, ElementsSortedWhenIterating) {

    // TODO: ...

    ASSERT_TRUE(set.empty());

    // TODO: ...

    ASSERT_EQ(1u, set.size());
    EXPECT_EQ(1u, set.count(3.2f));

    // TODO: ...

    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(3.2f));
    EXPECT_EQ(1u, set.count(4.1f));
    EXPECT_EQ(1u, set.count(1.1f));

    // TODO: ...

    auto iter = set.begin();
    EXPECT_FLOAT_EQ(0.3f, *iter++);
    EXPECT_FLOAT_EQ(1.1f, *iter++);
    EXPECT_FLOAT_EQ(3.2f, *iter++);
    EXPECT_FLOAT_EQ(4.1f, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(SetInt, ElementsSortedInDecreasingOrderWhenIterating) {

    struct Comparator {
        // TODO: ...
    };

    // TODO: ...

    auto iter = set.begin();
    EXPECT_EQ(3, *iter++);
    EXPECT_EQ(2, *iter++);
    EXPECT_EQ(1, *iter++);
    EXPECT_EQ(set.end(), iter);

    // TODO: ...

    iter = set.begin();
    EXPECT_EQ(4, *iter++);
    EXPECT_EQ(3, *iter++);
    EXPECT_EQ(2, *iter++);
    EXPECT_EQ(1, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(SetChar, InvalidComparatorThatCausesOnlyOneElementToBeInserted) {

    struct Comparator {
        // TODO: ...
    };

    // TODO: ...

    ASSERT_TRUE(set.empty());

    // TODO: ...

    ASSERT_EQ(1u, set.size());

    // TODO: ...

    ASSERT_EQ(1u, set.size());
}

TEST(SetChar, InvalidComparatorThatCausesMultipleCopiesOfTheSameElementToBeInserted) {

    struct Comparator {
        // TODO: ...
    };

    // TODO: ...

    ASSERT_TRUE(set.empty());

    // TODO: ...

    ASSERT_EQ(1u, set.size());

    // TODO: ...

    ASSERT_EQ(2u, set.size());
}

TEST(SetValue, CustomTypeAndComparator) {

    struct Value {
        // TODO: ...
    };

    struct Comparator {
        // TODO: ...
    };

    // TODO: ...

    ASSERT_TRUE(set.empty());

    // TODO: ...

    ASSERT_EQ(1u, set.size());
    EXPECT_EQ(1u, set.count(Value{1, 0}));

    // TODO: ...

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(Value{1, 0}));
    EXPECT_EQ(1u, set.count(Value{2, 0}));

    // TODO: ...

    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(Value{1, 0}));
    EXPECT_EQ(1u, set.count(Value{2, 0}));
    EXPECT_EQ(1u, set.count(Value{1, 1}));

    // TODO: ...

    ASSERT_EQ(4u, set.size());
    EXPECT_EQ(1u, set.count(Value{1, 0}));
    EXPECT_EQ(1u, set.count(Value{2, 0}));
    EXPECT_EQ(1u, set.count(Value{1, 1}));
    EXPECT_EQ(1u, set.count(Value{2, 2}));
}

TEST(SetInt, ElementsNotLessThanGivenValue) {

    // TODO: ...

    ASSERT_EQ(5u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(1u, set.count(2));
    EXPECT_EQ(1u, set.count(3));
    EXPECT_EQ(1u, set.count(4));
    EXPECT_EQ(1u, set.count(5));

    // TODO: ...

    EXPECT_EQ(3, *iter++);
    EXPECT_EQ(4, *iter++);
    EXPECT_EQ(5, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(MapStringString, CreateUsingInitializerList) {

    // TODO: ...

    ASSERT_EQ(3u, map.size());
    EXPECT_EQ("Poland", map["PL"]);
    EXPECT_EQ("Japan", map["JP"]);
    EXPECT_EQ("Germany", map["DE"]);
}

TEST(MapSetString, NestedCollections) {

    // TODO: ...

    ASSERT_TRUE(map.empty());

    // TODO: ...

    ASSERT_EQ(1u, map.size());
    ASSERT_EQ(1u, map.count("digits"));

    ASSERT_EQ(4u, map["digits"].size());
    EXPECT_EQ(1u, map["digits"].count("1"));
    EXPECT_EQ(1u, map["digits"].count("2"));
    EXPECT_EQ(1u, map["digits"].count("3"));
    EXPECT_EQ(1u, map["digits"].count("4"));
}

TEST(MultimapIntInt, RemoveRangeOfElements) {

    // TODO: ...

    ASSERT_EQ(8, multimap.size());
    EXPECT_EQ(1, multimap.count(1));
    EXPECT_EQ(4, multimap.count(2));
    EXPECT_EQ(3, multimap.count(3));

    // TODO: ...

    ASSERT_EQ(4, multimap.size());
    EXPECT_EQ(1, multimap.count(1));
    EXPECT_EQ(3, multimap.count(3));
}

TEST(UnorderedSetValue, CustomTypeHashAndComparator) {

    struct Value {
        // TODO: ...
    };

    struct Hash {
        // TODO: ...
    };

    struct Equal {
        // TODO: ...
    };

    // TODO: ...

    ASSERT_TRUE(unordered_set.empty());

    // TODO: ...

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1}));

    // TODO: ...

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1}));

    // TODO: ...

    ASSERT_EQ(4u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 2}));
}

TEST(UnorderedSetInt, BucketsAndLoadFactor) {

    // TODO: ...

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0 / 2.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ...

    ASSERT_EQ(2u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ...

    ASSERT_EQ(3u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(3.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ...

    ASSERT_EQ(4u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(4.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ...

    ASSERT_EQ(5u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ...

    ASSERT_EQ(10u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(10.0 / 11.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ...

    ASSERT_EQ(11u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(11.0 / 11.0, unordered_set.load_factor());
}
