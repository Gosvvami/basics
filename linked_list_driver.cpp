// Created by SwiftWare Lab on 9/24.
// CE 4SP4 - High Performance Programming
// Copyright (c) 2024 SwiftWare Lab

#include <iostream>
//#include <vector>
#include <benchmark/benchmark.h>
//#include "vec_add.h"
#include "linked_list.h"



/*static void BM_VECADD(benchmark::State &state) {
 auto m = state.range(0);
 std::vector<float> a(m, 1.0);
 std::vector<float> b(m, 2.0);

 for(auto _ : state) {
   std::vector<float> c;
   swiftware::hpp::vec_add(a, b, c);
 }
}*/

static void BM_BRUTEFORCE(benchmark::State &state){
    auto m = state.range(0);

    for(auto _ : state){
        state.PauseTiming();
        goswaa4::Node* head = goswaa4::GenLinkedList(m);
        state.ResumeTiming();
        goswaa4::BruteForceSort(head);
    }

}

static void BM_MERGESORT(benchmark::State &state){
    auto m = state.range(0);

    for(auto _ : state){
        state.PauseTiming();
        goswaa4::Node* head = goswaa4::GenLinkedList(m);
        state.ResumeTiming();
        goswaa4::MergeSort(head);
    }

}

BENCHMARK(BM_BRUTEFORCE)->Arg(20000)->Arg(40000)->Arg(60000)->Arg(80000);
BENCHMARK(BM_MERGESORT)->Arg(20000)->Arg(40000)->Arg(60000)->Arg(80000);

BENCHMARK_MAIN();
