#include <forward_list>
#include <map>
#include <ctime>
#include <unordered_map>

#include <iostream>

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



// MULTIMAP BENCHMARKS  ===============================================================================================



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

static void Small_multimapInsertN(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::multimap<Small, int> multimap{};

        for(std::size_t i = 0; i < size; i++) {
            Small inserted{};
            inserted.randomize();
            multimap.insert({ inserted, i });
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapInsertN)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_multimapClear(State& state) {  // NlogN zamiast N przez wstawianie elementow - trzeba odjac (baseline)

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::multimap<Small, int> multimap{};

        for(std::size_t i = 0; i < size; i++) {
            Small inserted{};
            inserted.randomize();
            multimap.insert({ inserted, i });
        }

        multimap.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapClear)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_multimapInsertErase(State& state) { // TODO Dla .randomized daje O(1) zamiast O(logN), dlaczego ?????

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Small inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        Small inserted{};
        inserted.randomize();  // brak wplywu na zlozonosc
        multimap.insert({ inserted, 0 });
        multimap.erase(inserted);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapInsertErase)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_multimapSwap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small, int> multimap1{};
    std::multimap<Small, int> multimap2{};

    for(std::size_t i = 0; i < size; i++) {
        Small inserted1{};
        Small inserted2{};
        inserted1.randomize();
        inserted2.randomize();
        multimap1.insert({ inserted1, i });
        multimap2.insert({ inserted2, i });
    }

    for(auto _ : state) {

        multimap1.swap(multimap2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapSwap)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_multimapCount(State& state) { // TODO Dla zasiegu wiekszego niz (1u, 1u << 14u) zlozonosc wieksza niz O(logN) DLACZEGO ??????????

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small, int> multimap{};


    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        Small counted{};
        counted.randomize();    // nie ma wplywu na zlozonosc

        multimap.count(counted);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapCount)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Small_multimapFind(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Small searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.find(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapFind)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_multimapEqualRange(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Small searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.equal_range(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapEqualRange)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_multimapLowerBound(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Small searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.lower_bound(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapLowerBound)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_multimapUpperBound(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Small searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.upper_bound(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_multimapUpperBound)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();



//  UNORDERED MULTIMAP BENCHMARK    ====================================================================================



static void Small_unorderedMultimapEmpty(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Small, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        uMultimap.empty();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapEmpty)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_unorderedMultimapSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Small, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        uMultimap.size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapSize)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_unorderedMultimapMaxSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Small, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        uMultimap.max_size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapMaxSize)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_unorderedMultimapInsertN(State& state) {  //  TODO Dlaczego O(n) zamiast O(1) ???????

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Small, int> uMultimap{};

    for(auto _ : state) {

        for(std::size_t i = 0; i < size; i++) {

            Small inserted{};
            inserted.randomize();
            uMultimap.insert({inserted, i});
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapInsertN)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_unorderedMultimapClear(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Small, int> uMultimap{};

    for(auto _ : state) {

        for(std::size_t i = 0; i < size; i++) {

            Small inserted{};
            inserted.randomize();
            uMultimap.insert({inserted, i});
        }

        uMultimap.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapClear)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

