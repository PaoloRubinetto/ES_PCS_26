#include <iostream>
#include <vector>
#include <algorithm>
#include "sorts.hpp"
#include "timecounter.h"
#include "randfiller.h"

int main() 
{
    randfiller rf;
    timecounter tc;

    std::cout << "Dim\tBubble\t\tInsertion\tSelection\tMerge\t\tQuick\t\tstd::sort\n";
    std::cout << "---------------------------------------------------------------------------------------------------------\n";

    int num_tests = 100; 

    for (int dim = 4; dim <= 8192; dim *= 2) 
    {
        std::vector<std::vector<int>> base_arrays(num_tests, std::vector<int>(dim));
        for (int i = 0; i < num_tests; i++) {
            rf.fill(base_arrays[i], -10000, 10000);
        }

        std::vector<std::vector<int>> v_bubble = base_arrays;
        std::vector<std::vector<int>> v_insertion = base_arrays;
        std::vector<std::vector<int>> v_selection = base_arrays;
        std::vector<std::vector<int>> v_merge = base_arrays;
        std::vector<std::vector<int>> v_quick = base_arrays;
        std::vector<std::vector<int>> v_std = base_arrays;

        tc.tic();
        for(int i=0; i<num_tests; i++) bubble_sort(v_bubble[i]);
        double tempo_b = tc.toc() / num_tests;

        tc.tic();
        for(int i=0; i<num_tests; i++) insertion_sort(v_insertion[i]);
        double tempo_i = tc.toc() / num_tests;

        tc.tic();
        for(int i=0; i<num_tests; i++) selection_sort(v_selection[i]);
        double tempo_s = tc.toc() / num_tests;

        tc.tic();
        for(int i=0; i<num_tests; i++) merge_sort(v_merge[i]);
        double tempo_m = tc.toc() / num_tests;

        tc.tic();
        for(int i=0; i<num_tests; i++) quicksort(v_quick[i]);
        double tempo_q = tc.toc() / num_tests;

        tc.tic();
        for(int i=0; i<num_tests; i++) std::sort(v_std[i].begin(), v_std[i].end());
        double tempo_std = tc.toc() / num_tests;

        std::cout << dim << "\t" 
                  << tempo_b << "\t" 
                  << tempo_i << "\t" 
                  << tempo_s << "\t" 
                  << tempo_m << "\t" 
                  << tempo_q << "\t" 
                  << tempo_std << std::endl;
    }

    return 0;
}