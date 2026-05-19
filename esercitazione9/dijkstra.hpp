#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "unidirected_graph.hpp"
#include <map>
#include <queue>
#include <limits>


template <typename T>
std::map<T, int> dijkstra(const unidirected_graph<T>& G, const T& src) {
    std::map<T, int> dist;
    const int INF = std::numeric_limits<int>::max();
    
    for (const T& node : G.all_nodes()) {
        dist[node] = INF;
    }
    
    // priority_queue che estrae il valore minimo {distanza, nodo}
    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int, T>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        T u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const T& v : G.neighours(u)) {
            int weight = 1; // Assumiamo peso 1 in assenza di pesi espliciti
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

#endif