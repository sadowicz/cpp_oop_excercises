#include "Large.h"
#include "BenchIncludes.h"

static void Large_LessThan(State& state) {

    Large a{};
    Large b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        bool res = a < b;
        DoNotOptimize(res);
    }
}

BENCHMARK(Large_LessThan);

static void Large_Equality(State& state) {

    Large a{};
    Large b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        bool res = a == b;
        DoNotOptimize(res);
    }
}

BENCHMARK(Large_Equality);

static void Large_Hash(State& state) {

    Large a{};

    a.randomize();

    for(auto _ : state) {

        auto res = std::hash<Large>{}(a);
        DoNotOptimize(res);
    }
}

BENCHMARK(Large_Hash);