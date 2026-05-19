#ifndef FIFO_HPP
#define FIFO_HPP

#include <queue>


class fifo {
private:
    std::queue<int> q; // Contenitore STL incapsulato

public:
    fifo() = default; // Costruttore di default

    void put(int x) { 
        q.push(x); // Inserisce in fondo alla coda
    }
    
    int get() { 
        int x = q.front(); // Legge l'elemento in testa
        q.pop();           // Lo rimuove dalla coda
        return x; 
    }
    
    bool empty() const { 
        return q.empty();  // Verifica se è vuoto
    }
};

#endif // FIFO_HPP