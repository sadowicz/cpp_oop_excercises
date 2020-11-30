#include "Large.h"
#include "BenchIncludes.h"

static void Large_LessThan(State& state) {

    Large a{};
    Large b{};

    for(auto _ : state) {

        a.randomize();
        b.randomize();

        a < b;
    }
}

static void Large_Equality(State& state) {

    Large a{};
    Large b{};

    for(auto _ : state) {

        a.randomize();
        b.randomize();

        a == b;
    }
}

static void Large_Hash(State& state) {

    Large a{};

    for(auto _ : state) {

        a.randomize();
        std::hash<Large>{}(a);
    }
}

BENCHMARK(Large_LessThan);
BENCHMARK(Large_Equality);
BENCHMARK(Large_Hash);