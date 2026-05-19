#include <iostream>
#include "unidirected_graph.hpp"
#include "fifo.hpp"
#include "lifo.hpp"
#include "graph_visit.hpp"
#include "recursive_dfs.hpp"
#include "dijkstra.hpp"
#include "graphviz.hpp"

int main() {
    // 1. Creiamo un grafo di test
    unidirected_graph<int> G;
    G.add_edge(1, 2);
    G.add_edge(1, 3);
    G.add_edge(2, 4);
    G.add_edge(2, 5);
    G.add_edge(3, 6);
    G.add_edge(3, 7);

    std::cout << "--- Inizio Esercitazione 9 ---\n";

    // 2. Visita in Ampiezza (BFS) con FIFO
    fifo q;
    auto bfsG = graph_visit(G, 1, q);
    export_to_dot(bfsG, "bfs_tree.dot");
    std::cout << "Visita BFS completata. File 'bfs_tree.dot' generato.\n";

    // 3. Visita in Profondità (DFS iterativa) con LIFO
    lifo s;
    auto dfsG = graph_visit(G, 1, s);
    export_to_dot(dfsG, "dfs_tree.dot");
    std::cout << "Visita DFS completata. File 'dfs_tree.dot' generato.\n";

    // 4. DFS Ricorsiva
    auto rec_dfsG = recursive_dfs(G, 1);
    export_to_dot(rec_dfsG, "rec_dfs_tree.dot");
    std::cout << "Visita DFS ricorsiva completata. File 'rec_dfs_tree.dot' generato.\n";

    // 5. Algoritmo di Dijkstra (assumendo pesi 1)
    auto dist = dijkstra(G, 1);
    std::cout << "\nDistanze minime dal nodo sorgente 1 (Dijkstra):\n";
    for (const auto& pair : dist) {
        std::cout << "Nodo " << pair.first << " -> Distanza: " << pair.second << "\n";
    }

    return 0;
}