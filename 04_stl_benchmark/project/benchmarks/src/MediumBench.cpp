#include "Medium.h"
#include "BenchIncludes.h"

static void Medium_LessThan(State& state) {

    Medium a{};
    Medium b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        a < b;
    }
}

BENCHMARK(Medium_LessThan);

static void Medium_Equality(State& state) {

    Medium a{};
    Medium b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        a == b;
    }
}

BENCHMARK(Medium_Equality);

static void Medium_Hash(State& state) {

    Medium a{};

    a.randomize();

    for(auto _ : state) {

        std::hash<Medium>{}(a);
    }
}

BENCHMARK(Medium_Hash);
