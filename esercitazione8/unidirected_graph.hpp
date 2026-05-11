#ifndef UNIDIRECTED_GRAPH_HPP
#define UNIDIRECTED_GRAPH_HPP

#include "unidirected_edge.hpp"
#include <set>
#include <map>
#include <stdexcept>

template <typename T>
class unidirected_graph {
private:
    std::set<T> m_nodes;
    std::set<unidirected_edge<T>> m_edges;
    std::map<T, std::set<T>> m_adj_list;
    
    std::map<unidirected_edge<T>, size_t> m_edge_to_id;
    std::map<size_t, unidirected_edge<T>> m_id_to_edge;
    size_t m_next_id;

public:
    unidirected_graph() : m_next_id(0) {}

    unidirected_graph(const unidirected_graph& other) = default;

    void add_edge(const T& u, const T& v) {
        unidirected_edge<T> edge(u, v);
        
        if (m_edges.find(edge) == m_edges.end()) {
            m_edges.insert(edge);
            m_nodes.insert(u);
            m_nodes.insert(v);
            
            m_adj_list[u].insert(v);
            m_adj_list[v].insert(u);
            
            m_edge_to_id[edge] = m_next_id;
            m_id_to_edge.insert({m_next_id, edge});
            m_next_id++;
        }
    }

    std::set<T> neighours(const T& node) const {
        auto it = m_adj_list.find(node);
        if (it != m_adj_list.end()) {
            return it->second;
        }
        return {};
    }

    std::set<unidirected_edge<T>> all_edges() const {
        return m_edges;
    }

    std::set<T> all_nodes() const {
        return m_nodes;
    }

    size_t edge_number(const unidirected_edge<T>& edge) const {
        auto it = m_edge_to_id.find(edge);
        if (it != m_edge_to_id.end()) {
            return it->second;
        }
        throw std::invalid_argument("Arco non presente nel grafo");
    }

    unidirected_edge<T> edge_at(size_t id) const {
        auto it = m_id_to_edge.find(id);
        if (it != m_id_to_edge.end()) {
            return it->second;
        }
        throw std::out_of_range("ID arco non valido");
    }

    unidirected_graph<T> operator-(const unidirected_graph<T>& other) const {
        unidirected_graph<T> result;
        for (const auto& edge : m_edges) {
            if (other.m_edges.find(edge) == other.m_edges.end()) {
                result.add_edge(edge.from(), edge.to());
            }
        }
        return result;
    }
};

#endif