#include <forward_list>
#include <map>
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

//  FORWARD LIST BENCHMARKS

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

static void Small_forwardListInsertAfterEraseAfter(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Small> fList{size};
    auto place = fList.begin();

    Small inserted{};

    for(auto _ : state) {

        fList.insert_after(place, inserted);
        fList.erase_after(place);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListInsertAfterEraseAfter)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListRandomizeElements(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Small> fList{size};

        for(auto& element : fList) {

            element.randomize();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListRandomizeElements)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListSort(State& state) {   // - 1 * RandomizeElements

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Small> fList{size};

        for(auto& element : fList) {

            element.randomize();
        }

        fList.sort();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListSort)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListMerge(State& state) {  //  - 2 * sort

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Small> fList1{size};

        for(auto& element : fList1) {

            element.randomize();
        }
        fList1.sort();


        std::forward_list<Small> fList2{size};

        for(auto& element : fList2) {

            element.randomize();
        }
        fList2.sort();


        fList1.merge(fList2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListMerge)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListBegin(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Small> fList{size};

    for(auto _ : state) {

        fList.begin();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListBegin)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListSpliceAfter(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Small> fList2{size};

    for(auto _ : state) {

        std::forward_list<Small> fList1{size};

        fList1.splice_after(fList1.begin(), fList2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListSpliceAfter)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListReverse(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Small> fList{size};

    for(auto _ : state) {

       fList.reverse();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListReverse)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListUnique(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Small> fList{size};
        fList.unique();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListUnique)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListRemove(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small toRemove{};
    toRemove.randomize();

    for(auto _ : state) {

        std::forward_list<Small> fList{size};
        fList.remove(toRemove);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListRemove)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_forwardListRemoveIf(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Small> fList{size};
        fList.remove_if([](Small small){ return true; });
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_forwardListRemoveIf)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

// MULTIMAP BENCHMARKS

static void Small_multimapEmpty(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Small inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        multimap.empty();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapEmpty)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_multimapSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Small inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        multimap.size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapSize)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_multimapMaxSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Small inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        multimap.max_size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapMaxSize)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();