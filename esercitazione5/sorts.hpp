
#ifndef SORTS_HPP
#define SORTS_HPP

#include <vector>
#include <iostream>
#include <algorithm>


template <typename T>
bool is_sorted(const std::vector<T>& vec) {
    if (vec.size() <= 1) return true;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i + 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void print_vector(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}


template <typename T>
void bubble_sort(std::vector<T>& vec) {
    if (vec.size() <= 1) return;
    bool swapped;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

template <typename T>
void selection_sort(std::vector<T>& vec) {
    if (vec.size() <= 1) return;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(vec[i], vec[min_idx]);
    }
}

template <typename T>
void insertion_sort(std::vector<T>& vec) {
    if (vec.size() <= 1) return;
    for (size_t i = 1; i < vec.size(); ++i) {
        T key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}


template <typename T>
void merge(std::vector<T>& vec, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (int i = 0; i < n1; ++i) L[i] = vec[p + i];
    for (int j = 0; j < n2; ++j) R[j] = vec[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void merge_sort(std::vector<T>& vec, int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2; 
        merge_sort(vec, p, q);
        merge_sort(vec, q + 1, r);
        merge(vec, p, q, r);
    }
}

template <typename T>
void merge_sort(std::vector<T>& vec) {
    if (vec.size() > 1) {
        merge_sort(vec, 0, vec.size() - 1);
    }
}

template <typename T>
int partition(std::vector<T>& vec, int p, int r) {
    T pivot = vec[r];
    int i = p - 1;

    for (int j = p; j < r; ++j) {
        if (vec[j] <= pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[r]);
    return i + 1;
}

template <typename T>
void quicksort(std::vector<T>& vec, int p, int r) {
    if (p < r) {
        int q = partition(vec, p, r);
        quicksort(vec, p, q - 1);
        quicksort(vec, q + 1, r);
    }
}

template <typename T>
void quicksort(std::vector<T>& vec) {
    if (vec.size() > 1) {
        quicksort(vec, 0, vec.size() - 1);
    }
}



template <typename T>
void insertion_sort_subarray(std::vector<T>& vec, int p, int r) {
    for (int i = p + 1; i <= r; ++i) {
        T key = vec[i];
        int j = i - 1;
        while (j >= p && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

template <typename T>
void hybrid_quicksort_recursive(std::vector<T>& vec, int p, int r) {
    const int THRESHOLD = 128; 

    if (r - p + 1 <= THRESHOLD) {
        insertion_sort_subarray(vec, p, r);
    } 
    else if (p < r) {
        int q = partition(vec, p, r);
        hybrid_quicksort_recursive(vec, p, q - 1);
        hybrid_quicksort_recursive(vec, q + 1, r);
    }
}

template <typename T>
void hybrid_quicksort(std::vector<T>& vec) {
    if (vec.size() > 1) {
        hybrid_quicksort_recursive(vec, 0, vec.size() - 1);
    }
}

#endif 