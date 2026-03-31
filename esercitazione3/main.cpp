#include <iostream>
#include "rational.hpp"

int main(void)
{
    rational<int> r(3, 6);
    std::cout << "Frazione semplificata (atteso 1/2): " << r << "\n";

    rational<int> normal(2, 3);
    rational<int> inf_val(5, 0); 
    std::cout << "Valore infinito: " << inf_val << "\n";
    
    rational<int> sum_inf = normal + inf_val;
    std::cout << "2/3 + Inf = " << sum_inf << "\n";

    rational<int> nan_val(0, 0);
    std::cout << "Valore Not-a-Number: " << nan_val << "\n";

    return 0;
}