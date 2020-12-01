#include "Small.h"
#include "BenchIncludes.h"

static void Small_LessThan(State& state) {

    Small a{};
    Small b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        a < b;
    }
}

BENCHMARK(Small_LessThan);

static void Small_Equality(State& state) {

    Small a{};
    Small b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        a == b;
    }
}

BENCHMARK(Small_Equality);

static void Small_Hash(State& state) {

    Small a{};
    a.randomize();

    for(auto _ : state) {

        std::hash<Small>{}(a);
    }
}

BENCHMARK(Small_Hash);
