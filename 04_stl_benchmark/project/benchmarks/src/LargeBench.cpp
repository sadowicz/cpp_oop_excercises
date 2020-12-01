#include "Large.h"
#include "BenchIncludes.h"

static void Large_LessThan(State& state) {

    Large a{};
    Large b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        a < b;
    }
}

BENCHMARK(Large_LessThan);

static void Large_Equality(State& state) {

    Large a{};
    Large b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        a == b;
    }
}

BENCHMARK(Large_Equality);

static void Large_Hash(State& state) {

    Large a{};

    a.randomize();

    for(auto _ : state) {

        std::hash<Large>{}(a);
    }
}

BENCHMARK(Large_Hash);