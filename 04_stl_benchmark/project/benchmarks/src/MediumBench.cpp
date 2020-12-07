#include "Medium.h"
#include "BenchIncludes.h"

static void Medium_LessThan(State& state) {

    Medium a{};
    Medium b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        bool res = a < b;
        DoNotOptimize(res);
    }
}

BENCHMARK(Medium_LessThan);

static void Medium_Equality(State& state) {

    Medium a{};
    Medium b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        bool res = a == b;
        DoNotOptimize(res);
    }
}

BENCHMARK(Medium_Equality);

static void Medium_Hash(State& state) {

    Medium a{};

    a.randomize();

    for(auto _ : state) {

        auto res = std::hash<Medium>{}(a);
        DoNotOptimize(res);
    }
}

BENCHMARK(Medium_Hash);
