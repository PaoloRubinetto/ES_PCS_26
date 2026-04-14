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

    std::cout << "Dimensione\tBubble\t\tInsertion\tSelection\tstd::sort\n";
    std::cout << "---------------------------------------------------------------------------------\n";

    for (int dim = 4; dim <= 8192; dim *= 2) 
    {
        std::vector<int> master_vec(dim);
        rf.fill(master_vec, -10000, 10000);

        std::vector<int> v_bubble = master_vec;
        std::vector<int> v_insertion = master_vec;
        std::vector<int> v_selection = master_vec;
        std::vector<int> v_stdsort = master_vec;

        tc.tic();
        bubble_sort(v_bubble);
        double tempo_b = tc.toc();

        tc.tic();
        insertion_sort(v_insertion);
        double tempo_i = tc.toc();

        tc.tic();
        selection_sort(v_selection);
        double tempo_s = tc.toc();

        tc.tic();
        std::sort(v_stdsort.begin(), v_stdsort.end());
        double tempo_std = tc.toc();

        std::cout << dim << "\t\t" 
                  << tempo_b << "\t" 
                  << tempo_i << "\t" 
                  << tempo_s << "\t" 
                  << tempo_std << std::endl;
    }

    return 0;
}