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

BENCHMARK(Medium_LessThan);
