#ifndef GRAPHVIZ_HPP
#define GRAPHVIZ_HPP

#include "unidirected_graph.hpp"
#include <fstream>
#include <string>

template <typename T>
void export_to_dot(const unidirected_graph<T>& G, const std::string& filename) {
    std::ofstream out(filename);
    out << "graph G {\n"; // "graph" e non "digraph" per grafi non orientati
    for (const auto& edge : G.all_edges()) {
        out << "    " << edge.from() << " -- " << edge.to() << ";\n";
    }
    out << "}\n";
    out.close();
}

#endif