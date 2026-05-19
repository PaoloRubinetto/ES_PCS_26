#ifndef LIFO_HPP
#define LIFO_HPP

#include <stack>


class lifo {
private:
    std::stack<int> s; // Contenitore STL incapsulato

public:
    lifo() = default; // Costruttore di default

    void put(int x) { 
        s.push(x); // Inserisce in cima allo stack
    }
    
    int get() { 
        int x = s.top(); // Legge l'elemento in cima
        s.pop();         // Lo rimuove dallo stack
        return x; 
    }
    
    bool empty() const { 
        return s.empty(); // Verifica se è vuoto
    }
};

#endif