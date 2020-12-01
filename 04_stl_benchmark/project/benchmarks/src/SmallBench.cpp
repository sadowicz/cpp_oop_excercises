#include <forward_list>
#include <ctime>

#include "Small.h"
#include "BenchIncludes.h"


static void Small_LessThan(State& state) {

    Small a{};
    Small b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        a < b;
    }
}

BENCHMARK(Small_LessThan);

static void Small_Equality(State& state) {

    Small a{};
    Small b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {

        a == b;
    }
}

BENCHMARK(Small_Equality);

static void Small_Hash(State& state) {

    Small a{};
    a.randomize();

    for(auto _ : state) {

        std::hash<Small>{}(a);
    }
}

BENCHMARK(Small_Hash);

static void Small_forwardListFront(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Small> fList{size};

    for(auto _ : state) {

        fList.front();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListFront)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListEmpty(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Small> fList{size};

    for(auto _ : state) {

        fList.empty();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListEmpty)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListMaxSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Small> fList{size};

    for(auto _ : state) {

        fList.max_size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListMaxSize)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListCreate(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Small> fList{size};
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListCreate)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListCreateAndClear(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Small> fList{size};
        fList.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListCreateAndClear)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_Rand(State& state) {

    for(auto _ : state) {

        auto number = rand() % 100;
    }
}

BENCHMARK(Small_Rand);

/*static void Small_forwardListInsertEraseAfterRandElement(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Small> fList{size};
    auto iter = fList.before_begin();
    Small inserted{};

    for(auto _ : state) {

        auto index = rand() % size;

        fList.insert_after(iter + index, inserted);
        fList.erase_after(iter + index);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListInsertEraseAfterRandElement)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();*/

static void Small_forwardListPushFrontPopFront(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Small> fList{size};
    Small inserted{};

    for(auto _ : state) {

        fList.push_front(inserted);
        fList.pop_front();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListPushFrontPopFront)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListResizeToRand(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    auto maxResize = 4 * size + 1;
    srand((unsigned int)time(nullptr));

    std::forward_list<Small> fList{size};

    for(auto _ : state) {

        fList.resize(rand() % maxResize);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListResizeToRand)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListSwap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Small> fList1{size};
    std::forward_list<Small> fList2{size};

    for(auto _ : state) {

        fList1.swap(fList2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListSwap)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();