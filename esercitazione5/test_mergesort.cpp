
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include "randfiller.h"
#include "sorts.hpp"

std::vector<int> random_number(randfiller& rf) {
    std::vector<int> dim_vec;
    dim_vec.resize(1); 
    rf.fill(dim_vec, 1, 1000); 
    return dim_vec;
}

int main(void) {
    randfiller rf; 

    for (size_t i = 0; i < 100; i++) {
        std::vector<int> dim_vec = random_number(rf);
        std::vector<int> vi;
        vi.resize(dim_vec.at(0)); 
        rf.fill(vi, -500, 500);   
        
        merge_sort(vi);
        
        if (!is_sorted(vi)) {
            std::cout << "Test Failed: the vector number " << i << " is not sorted (MergeSort). \n";
            return EXIT_FAILURE;
        }
    }

    std::vector<std::string> vs = {"pc", "tastiera", "lettere" , "cassa", "noia", "ipad"};
    vs.push_back("pennarello");

    merge_sort(vs);
    
    if (!is_sorted(vs)) {
        std::cout << "Test Failed: the String vector is not sorted! \n";
        return EXIT_FAILURE;
    }

    std::cout << "MergeSort: Test Successful \n";
    return EXIT_SUCCESS;
}