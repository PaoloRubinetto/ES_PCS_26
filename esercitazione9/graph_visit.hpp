#ifndef GRAPH_VISIT_HPP
#define GRAPH_VISIT_HPP

#include "unidirected_graph.hpp"
#include <map>

template <typename Container, typename T>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& G, const T& src, Container& c) {
    unidirected_graph<T> tree;
    std::map<T, bool> visited;
    std::map<T, T> parent;

    // Inizializza tutto a false
    for (const T& node : G.all_nodes()) {
        visited[node] = false;
    }

    c.put(src);
    
    while (!c.empty()) {
        T u = c.get();
        
        if (!visited[u]) {
            visited[u] = true; 
            
            // Aggiungiamo l'arco all'albero (se non è la radice)
            if (u != src) {
                tree.add_edge(parent[u], u);
            }
            
            // Usiamo il tuo metodo "neighours"
            for (const T& v : G.neighours(u)) {
                if (!visited[v]) {
                    c.put(v);
                    parent[v] = u; 
                }
            }
        }
    }
    return tree;
}

#endif