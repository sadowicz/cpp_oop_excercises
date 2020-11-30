#include "Small.h"
#include "BenchIncludes.h"

static void Small_LessThan(State& state) {

    Small a{};
    Small b{};

    for(auto _ : state) {

        a.randomize();
        b.randomize();

        a < b;
    }
}

static void Small_Equality(State& state) {

    Small a{};
    Small b{};

    for(auto _ : state) {

        a.randomize();
        b.randomize();

        a == b;
    }
}

static void Small_Hash(State& state) {

    Small a{};

    for(auto _ : state) {

        a.randomize();
        std::hash<Small>{}(a);
    }
}

BENCHMARK(Small_LessThan);
BENCHMARK(Small_Equality);
BENCHMARK(Small_Hash);
