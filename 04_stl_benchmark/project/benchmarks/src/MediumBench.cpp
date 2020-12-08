#include <forward_list>
#include <map>
#include <unordered_map>

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



//  FORWARD LIST BENCHMARKS     ========================================================================================



static void Medium_forwardListFront(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Medium> fList{size};

    for(auto _ : state) {

        auto res = fList.front();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListFront)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Medium_forwardListEmpty(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Medium> fList{size};

    for(auto _ : state) {

        auto res = fList.empty();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListEmpty)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Medium_forwardListMaxSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Medium> fList{size};

    for(auto _ : state) {

        auto res = fList.max_size();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListMaxSize)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Medium_forwardListCreate(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Medium> fList{size};
        DoNotOptimize(fList);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListCreate)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Medium_forwardListCreateAndClear(State& state) { // - forwardListCreate ( baseline )

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Medium> fList{size};
        DoNotOptimize(fList);

        fList.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListCreateAndClear)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Medium_Rand(State& state) {

    for(auto _ : state) {

        auto number = rand() % 100;
        DoNotOptimize(number);
    }
}

BENCHMARK(Medium_Rand);

static void Medium_forwardListPushFrontPopFront(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Medium> fList{size};
    Medium inserted{};

    for(auto _ : state) {

        fList.push_front(inserted);
        fList.pop_front();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListPushFrontPopFront)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Medium_forwardListResizeToRand(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    auto maxResize = 4 * size + 1;
    srand((unsigned int)time(nullptr));

    std::forward_list<Medium> fList{size};

    for(auto _ : state) {

        fList.resize(rand() % maxResize);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListResizeToRand)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Medium_forwardListSwap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Medium> fList1{size};
    std::forward_list<Medium> fList2{size};

    for(auto _ : state) {

        fList1.swap(fList2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListSwap)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Medium_forwardListInsertAfterEraseAfter(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Medium> fList{size};
    auto place = fList.begin();

    Medium inserted{};

    for(auto _ : state) {

        fList.insert_after(place, inserted);
        fList.erase_after(place);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListInsertAfterEraseAfter)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Medium_forwardListRandomizeElements(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Medium> fList{size};

        for(auto& element : fList) {

            element.randomize();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListRandomizeElements)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Medium_forwardListSort(State& state) {   // - 1 * RandomizeElements
                                                    // TODO Dlaczego dla Medium O(N) zamiast O(NlogN) ???????
    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Medium> fList{size};

        for(auto& element : fList) {

            element.randomize();
        }

        fList.sort();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListSort)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_forwardListMerge(State& state) {  //  - 2 * sort

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Medium> fList1{size};

        for(auto& element : fList1) {

            element.randomize();
        }
        fList1.sort();


        std::forward_list<Medium> fList2{size};

        for(auto& element : fList2) {

            element.randomize();
        }
        fList2.sort();


        fList1.merge(fList2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListMerge)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_forwardListSpliceAfter(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Medium> fList2{size};

    for(auto _ : state) {

        std::forward_list<Medium> fList1{size};

        fList1.splice_after(fList1.begin(), fList2);    // .begin() O(1) nie wplywa na zlozonosc
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListSpliceAfter)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_forwardListReverse(State& state) {    // TODO Why O(NlogN) and not O(N)

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::forward_list<Medium> fList{size};

    for(auto _ : state) {

        fList.reverse();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListReverse)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_forwardListUnique(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Medium> fList{size};
        fList.unique();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListUnique)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Medium_forwardListRemove(State& state) { // TODO Dlaczego O(NlogN) zamiast O(N)

    auto N = state.range(0);
    auto size = (std::size_t)N;
    Medium toRemove{};
    toRemove.randomize();

    for(auto _ : state) {

        std::forward_list<Medium> fList{size};
        fList.remove(toRemove);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListRemove)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_forwardListRemoveIf(State& state) {  // TODO Dlaczego O(NlogN) zamiast O(N)

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::forward_list<Medium> fList{size};
        fList.remove_if([](Medium small){ return true; });
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_forwardListRemoveIf)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();



// MULTIMAP BENCHMARKS  ===============================================================================================



static void Medium_multimapEmpty(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Medium inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        auto res = multimap.empty();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_multimapEmpty)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_multimapSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Medium inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        auto res = multimap.size();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_multimapSize)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_multimapMaxSize(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Medium inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        auto res = multimap.max_size();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_multimapMaxSize)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_multimapInsertN(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::multimap<Medium, int> multimap{};

        for(std::size_t i = 0; i < size; i++) {
            Medium inserted{};
            inserted.randomize();
            multimap.insert({ inserted, i });
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_multimapInsertN)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_multimapClear(State& state) {  //trzeba odjac (baseline) InsertN

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::multimap<Medium, int> multimap{};

        for(std::size_t i = 0; i < size; i++) {
            Medium inserted{};
            inserted.randomize();
            multimap.insert({ inserted, i });
        }

        multimap.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_multimapClear)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_multimapInsertErase(State& state) { // TODO Dla .randomized daje O(1) zamiast O(logN), dlaczego ?????

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {
        Medium inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        Medium inserted{};
        inserted.randomize();  // brak wplywu na zlozonosc
        multimap.insert({ inserted, 0 });
        multimap.erase(inserted);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_multimapInsertErase)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_multimapSwap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium, int> multimap1{};
    std::multimap<Medium, int> multimap2{};

    for(std::size_t i = 0; i < size; i++) {
        Medium inserted1{};
        Medium inserted2{};
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

BENCHMARK(Medium_multimapSwap)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_multimapCount(State& state) {    // TODO Dlaczego wychodzi O(1) ?????

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium, int> multimap{};


    for(std::size_t i = 0; i < size; i++) {

        Medium inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    for(auto _ : state) {

        Medium counted{};
        counted.randomize();    // nie ma wplywu na zlozonosc

        multimap.count(counted);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_multimapCount)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_multimapFind(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Medium inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Medium searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.find(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_multimapFind)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_multimapEqualRange(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Medium inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Medium searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.equal_range(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_multimapEqualRange)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_multimapLowerBound(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Medium inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Medium searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.lower_bound(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_multimapLowerBound)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Medium_multimapUpperBound(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium, int> multimap{};

    for(std::size_t i = 0; i < size; i++) {

        Medium inserted{};
        inserted.randomize();
        multimap.insert({ inserted, i });
    }

    Medium searched{};
    searched.randomize();

    for(auto _ : state) {

        multimap.upper_bound(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Medium_multimapUpperBound)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

/*

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

        auto res = uMultimap.empty();
        DoNotOptimize(res);
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

        auto res = uMultimap.size();
        DoNotOptimize(res);
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

        auto res = uMultimap.max_size();
        DoNotOptimize(res);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapMaxSize)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_unorderedMultimapInsertN(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for(auto _ : state) {

        std::unordered_multimap<Small, int> uMultimap{};

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

    for(auto _ : state) {

        std::unordered_multimap<Small, int> uMultimap{};

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

static void Small_unorderedMultimapInsertErase(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Small, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        Small inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, 0});
        uMultimap.erase(inserted);  // O(1), jeśli elementy sie nie powtarzają to podobnie do insert
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapInsertErase)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_unorderedMultimapSwap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Small, int> uMultimap1{};
    std::unordered_multimap<Small, int> uMultimap2{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted1{};
        Small inserted2{};
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

BENCHMARK(Small_unorderedMultimapSwap)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_unorderedMultimapCount(State& state) {    // wychodzi O(n) bo im wieksze N tym czesciej klucze
    // sie powtarzaja, a zlozonosc .count() jest liniowa w obrebie
    auto N = state.range(0);                           // tego samego klucza, wiec dla wiekszej ilosci powtorzen
    auto size = (std::size_t)N;                             // mierzony jest wiekszy czas. Zatem zlozonosc jest posrednio
    // zalezna od N
    std::unordered_multimap<Small, int> uMultimap{};        // TODO Dlaczego dla range > 1u << 14u zlozonosc > O(N) w release???

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        Small counted{};
        counted.randomize();
        uMultimap.count(counted);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapCount)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Small_unorderedMultimapFind(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Small, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        Small searched{};
        searched.randomize();
        uMultimap.find(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapFind)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_unorderedMultimapEqualRange(State& state) {   // powod liniowosci taki sam jak w Small_unorderedMultimapCount

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multimap<Small, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        Small searched{};
        searched.randomize();
        uMultimap.equal_range(searched);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapEqualRange)->RangeMultiplier(2)->Range(1u, 1u << 14u)->Complexity();

static void Small_unorderedMultimapRehash(State& state) {   // TODO: Dlaczego dla release O(NlogN) a dla debug O(N) ????

    auto N = state.range(0);
    auto size = (std::size_t)N;

    srand(time(nullptr));

    std::unordered_multimap<Small, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    uMultimap.max_load_factor(size);    // bo przekraczanie max_load_factor powodowalo zlozonosc < O(n) z duzym bledem

    for(auto _ : state) {

        uMultimap.rehash(rand() % size + 1);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapRehash)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();

static void Small_unorderedMultimapReserve(State& state) {  // TODO: Dlaczego dla release O(NlogN) a dla debug O(N) ????

    auto N = state.range(0);
    auto size = (std::size_t)N;

    srand(time(nullptr));

    std::unordered_multimap<Small, int> uMultimap{};

    for(std::size_t i = 0; i < size; i++) {

        Small inserted{};
        inserted.randomize();
        uMultimap.insert({inserted, i});
    }

    for(auto _ : state) {

        uMultimap.max_load_factor(rand() % size + 1);    // O(1) - brak wplywu na zlozonosc
        uMultimap.reserve(size);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Small_unorderedMultimapReserve)->RangeMultiplier(2)->Range(1u, 1u << 16u)->Complexity();
 */