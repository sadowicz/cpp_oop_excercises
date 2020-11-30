#include "Medium.h"
#include "BenchIncludes.h"

static void Medium_LessThan(State& state) {

    Medium a{};
    Medium b{};

    for(auto _ : state) {

        a.randomize();
        b.randomize();

        a < b;
    }
}

static void Medium_Equality(State& state) {

    Medium a{};
    Medium b{};

    for(auto _ : state) {

        a.randomize();
        b.randomize();

        a == b;
    }
}

static void Medium_Hash(State& state) {

    Medium a{};

    for(auto _ : state) {

        a.randomize();
        std::hash<Medium>{}(a);
    }
}

BENCHMARK(Medium_LessThan);
BENCHMARK(Medium_Equality);
BENCHMARK(Medium_Hash);
