#include <forward_list>
#include <map>
#include <unordered_map>

#include "Large.h"
#include "BenchIncludes.h"

const int Medium_maxIter = 1u << 8u;   // dla wyzszego CLion sie konczy na niekturych benchmarkach

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



//  FORWARD LIST BENCHMARKS     ========================================================================================



static void Large_forwardListFront(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Large> fList{size};

    for(auto _ : state) {

        auto res = fList.front();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListFront)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListEmpty(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Large> fList{size};

    for(auto _ : state) {

        auto res = fList.empty();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListEmpty)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListMaxSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Large> fList{size};

    for(auto _ : state) {

        auto res = fList.max_size();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListMaxSize)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListCreate(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Large> fList{size};
        DoNotOptimize(fList);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListCreate)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListCreateAndClear(State& state) { // - forwardListCreate ( baseline )

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Large> fList{size};
        DoNotOptimize(fList);

        fList.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListCreateAndClear)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_Rand(State& state) {

    for(auto _ : state) {

        auto number = rand() % 100;
        DoNotOptimize(number);
    }
}

BENCHMARK(Large_Rand);

static void Large_forwardListPushFrontPopFront(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Large> fList{size};
    Large inserted{};

    for(auto _ : state) {

        fList.push_front(inserted);
        fList.pop_front();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListPushFrontPopFront)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListResizeToRand(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    auto maxResize = 4 * size + 1;
    srand((unsigned int)time(nullptr));

    std::forward_list<Large> fList{size};

    for(auto _ : state) {

        fList.resize(rand() % maxResize);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListResizeToRand)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListSwap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Large> fList1{size};
    std::forward_list<Large> fList2{size};

    for(auto _ : state) {

        fList1.swap(fList2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListSwap)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListInsertAfterEraseAfter(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Large> fList{size};
    auto place = fList.begin();

    Large inserted{};

    for(auto _ : state) {

        fList.insert_after(place, inserted);
        fList.erase_after(place);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListInsertAfterEraseAfter)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListRandomizeElements(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Large> fList{size};

        for(auto& element : fList) {

            element.randomize();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListRandomizeElements)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListSort(State& state) {   // - 1 * RandomizeElements

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Large> fList{size};

        for(auto& element : fList) {

            element.randomize();
        }

        fList.sort();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListSort)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListMerge(State& state) {  //  - 2 * sort

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Large> fList1{size};

        for(auto& element : fList1) {

            element.randomize();
        }
        fList1.sort();


        std::forward_list<Large> fList2{size};

        for(auto& element : fList2) {

            element.randomize();
        }
        fList2.sort();


        fList1.merge(fList2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListMerge)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListSpliceAfter(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Large> fList2{size};

    for(auto _ : state) {

        std::forward_list<Large> fList1{size};

        fList1.splice_after(fList1.begin(), fList2);    // .begin() O(1) nie wplywa na zlozonosc
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListSpliceAfter)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListReverse(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Large> fList{size};

    for(auto _ : state) {

        fList.reverse();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListReverse)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListUnique(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Large> fList{size};
        fList.unique();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListUnique)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListRemove(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    Large toRemove{};
    toRemove.randomize();

    for(auto _ : state) {

        std::forward_list<Large> fList{size};
        fList.remove(toRemove);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListRemove)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_forwardListRemoveIf(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Large> fList{size};
        fList.remove_if([](Large small){ return true; });
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_forwardListRemoveIf)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();



// MULTIMAP BENCHMARKS  ===============================================================================================



static void Large_multimapEmpty(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Large inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        auto res = multimap.empty();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_multimapEmpty)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_multimapSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Large inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        auto res = multimap.size();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_multimapSize)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_multimapMaxSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Large inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        auto res = multimap.max_size();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_multimapMaxSize)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_multimapInsertN(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::multimap<Large, int> multimap{};

        for(std::size_t i = 0; i < size; i++) {
            Large inserted{};
            inserted.randomize();
            multimap.insert({ inserted, i });
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_multimapInsertN)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_multimapClear(State& state) {  //trzeba odjac (baseline) InsertN

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::multimap<Large, int> multimap{};

        for(std::size_t i = 0; i < size; i++) {
            Large inserted{};
            inserted.randomize();
            multimap.insert({ inserted, i });
        }

        multimap.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_multimapClear)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_multimapInsertErase(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Large inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        Large inserted{};
        inserted.randomize();
        multimap.insert({ inserted, 0 });
        multimap.erase(inserted);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_multimapInsertErase)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_multimapSwap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large, int> multimap1{};
    std::multimap<Large, int> multimap2{};

    for(std::size_t i = 0; i < size; i++) {
        Large inserted1{};
        Large inserted2{};
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

BENCHMARK(Large_multimapSwap)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_multimapCount(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large, int> multimap{};


    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        Large counted{};
        counted.randomize();

        multimap.count(counted);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_multimapCount)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_multimapFind(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Large searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.find(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_multimapFind)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_multimapEqualRange(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Large searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.equal_range(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_multimapEqualRange)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_multimapLowerBound(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Large searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.lower_bound(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_multimapLowerBound)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_multimapUpperBound(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Large searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.upper_bound(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_multimapUpperBound)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();



//  UNORDERED MULTIMAP BENCHMARK    ====================================================================================



static void Large_unorderedMultimapEmpty(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Large, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        auto res = uMultimap.empty();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapEmpty)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_unorderedMultimapSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Large, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        auto res = uMultimap.size();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapSize)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_unorderedMultimapMaxSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Large, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        auto res = uMultimap.max_size();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapMaxSize)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_unorderedMultimapInsertN(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::unordered_multimap<Large, int> uMultimap{};

        for(std::size_t i = 0; i < size; i++) {

            Large inserted{};
            inserted.randomize();
            uMultimap.insert({inserted, i});
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapInsertN)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_unorderedMultimapClear(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::unordered_multimap<Large, int> uMultimap{};

        for(std::size_t i = 0; i < size; i++) {

            Large inserted{};
            inserted.randomize();
            uMultimap.insert({inserted, i});
        }

        uMultimap.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapClear)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_unorderedMultimapInsertErase(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Large, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        Large inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, 0});
        uMultimap.erase(inserted);  // O(1), jeśli elementy sie nie powtarzają to podobnie do insert
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapInsertErase)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_unorderedMultimapSwap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Large, int> uMultimap1{};
    std::unordered_multimap<Large, int> uMultimap2{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted1{};
        Large inserted2{};
        inserted1.randomize();
        inserted2.randomize();
        uMultimap1.insert({inserted1, i});
        uMultimap2.insert({inserted2, i + 1});
    }

    for(auto _ : state) {

        uMultimap1.swap(uMultimap2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapSwap)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_unorderedMultimapCount(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Large, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        Large counted{};
        counted.randomize();
        uMultimap.count(counted);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapCount)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_unorderedMultimapFind(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Large, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        Large searched{};
        searched.randomize();
        uMultimap.find(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapFind)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_unorderedMultimapEqualRange(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Large, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        Large searched{};
        searched.randomize();
        uMultimap.equal_range(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapEqualRange)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_unorderedMultimapRehash(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    srand(time(nullptr));

    std::unordered_multimap<Large, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    uMultimap.max_load_factor(size);    // bo przekraczanie max_load_factor powodowalo zlozonosc < O(n) z duzym bledem

    for(auto _ : state) {

        uMultimap.rehash(rand() % size + 1);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapRehash)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();

static void Large_unorderedMultimapReserve(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    srand(time(nullptr));

    std::unordered_multimap<Large, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Large inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        uMultimap.max_load_factor(rand() % size + 1);    // O(1) - brak wplywu na zlozonosc
        uMultimap.reserve(size);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Large_unorderedMultimapReserve)->RangeMultiplier(2)->Range(1u, Medium_maxIter)->Complexity();
