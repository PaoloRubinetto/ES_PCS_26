#include <iostream>
#include "unidirected_graph.hpp"

int main() {
    unidirected_edge<int> e1(5, 2);
    std::cout << e1 << "\n";
    std::cout << e1.from() << " " << e1.to() << "\n";

    unidirected_graph<int> G1;
    G1.add_edge(1, 2);
    G1.add_edge(2, 3);
    G1.add_edge(3, 1);
    G1.add_edge(3, 4);

    for (int n : G1.all_nodes()) std::cout << n << " ";
    std::cout << "\n";
    for (auto e : G1.all_edges()) std::cout << e << " ";
    std::cout << "\n";
    
    for (int n : G1.neighours(3)) std::cout << n << " ";
    std::cout << "\n";

    unidirected_edge<int> target(1, 3);
    size_t id = G1.edge_number(target);
    std::cout << id << "\n";
    std::cout << G1.edge_at(id) << "\n";

    unidirected_graph<int> G2;
    G2.add_edge(1, 2);
    G2.add_edge(2, 3);
    
    unidirected_graph<int> G_diff = G1 - G2;
    for (auto e : G_diff.all_edges()) std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}