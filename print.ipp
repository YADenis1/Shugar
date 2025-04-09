#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

template <typename T>
void print(T** array2d, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::cout << array2d[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void print(T** array2d, int rows, int cols) {
    print(array2d, (size_t)rows, (size_t)cols);
}

template <typename T, size_t rows, size_t cols>
void print(T(&array2d)[rows][cols]) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < rows; j++) {
            std::cout << array2d[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void print(T* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void print(T* array2d, int size) {
    print(array2d, (size_t)size);
}

template <typename T, size_t size>
void print(T(&array)[size]) {
    for (size_t i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void print(const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename... T>
void print(T... args) {
    (std::cout << ... << args) << std::endl;
}

template <typename T>
void print(std::initializer_list<T> elements) {
    for (T element : elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void print(std::vector<T> vec) {
    if (vec.empty()) {
        std::cout << "empty vector";
    }
    else {
        for (auto element : vec) {
            std::cout << element << " ";
        }
    }
}

template<typename T, typename U>
void print(std::map<T, U> mp) {
    if (mp.empty()) {
        std::cout << "empty map";
    }
    else {
        for (const auto& [k, v] : mp) {
            std::cout << k << ":" << v << " ";
        }
    }
}

template<typename T>
void print(std::set<T> st) {
    if (st.empty()) {
        std::cout << "empty set";
    }
    else {
        for (auto el : st) {
            std::cout << el << " ";
        }
    }
}