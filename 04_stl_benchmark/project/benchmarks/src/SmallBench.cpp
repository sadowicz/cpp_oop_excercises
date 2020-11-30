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

BENCHMARK(LessThanSmall);
