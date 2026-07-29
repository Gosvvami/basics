// Created by SwiftWare Lab on 9/24.
// CE 4SP4 - High Performance Programming
// Copyright (c) 2024 SwiftWare Lab

#include <iostream>
#include <benchmark/benchmark.h>
#include "linked_list.h"

// benchmark testing function for BruteForce based on BM_VECADD
static void BM_BRUTEFORCE(benchmark::State &state){
    auto m = state.range(0);

    for(auto _ : state){
        state.PauseTiming();
        goswaa4::Node* head = goswaa4::GenLinkedList(m);
        state.ResumeTiming();
        goswaa4::BruteForceSort(head);
    }

}

// benchmark testing function for MergeSort based on BM_VECADD
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
