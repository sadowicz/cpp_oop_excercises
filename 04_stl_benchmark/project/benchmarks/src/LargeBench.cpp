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

BENCHMARK(Large_LessThan);
