#include "Small.h"
#include "BenchIncludes.h"

static void LessThanSmall(State& state) {

    Small a{};
    Small b{};

    for(auto _ : state) {

        a.randomize();
        b.randomize();

        a < b;
    }
}

static void EqualitySmall(State& state) {

    Small a{};
    Small b{};

    for(auto _ : state) {

        a.randomize();
        b.randomize();

        a == b;
    }
}

static void HashSmall(State& state) {

    Small a{};

    for(auto _ : state) {

        a.randomize();
        std::hash<Small>{}(a);
    }
}

BENCHMARK(LessThanSmall);
BENCHMARK(EqualitySmall);
BENCHMARK(HashSmall);
