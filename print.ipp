#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iomanip>
#include <sstream>

template <typename T>
void print(T** array2d, size_t rows, size_t cols) {
    size_t mxlen = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::stringstream s;
            s << array2d[i][j];
            mxlen = std::max(mxlen, s.str().length());
        }
    }
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::cout << std::setw(mxlen) << std::left << array2d[i][j] << " ";
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
    size_t mxlen = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::stringstream s;
            s << array2d[i][j];
            mxlen = std::max(mxlen, s.str().length());
        }
    }
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::cout << std::setw(mxlen) << std::left << array2d[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void print(T* arr, size_t size) {
    size_t mxlen = 0;
    for (size_t i = 0; i < size; i++) {
        std::stringstream s;
        s << arr[i];
        mxlen = std::max(mxlen, s.str().length());
    }
    for (size_t i = 0; i < size; i++) {
        std::cout << std::setw(mxlen) << std::left << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T, size_t size>
void print(T(&arr)[size]) {
    size_t mxlen = 0;
    for (size_t i = 0; i < size; i++) {
        std::stringstream s;
        s << arr[i];
        mxlen = std::max(mxlen, s.str().length());
    }
    for (size_t i = 0; i < size; i++) {
        std::cout << std::setw(mxlen) << std::left << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void print(const T* arr, size_t size) {
    size_t mxlen = 0;
    for (size_t i = 0; i < size; i++) {
        std::stringstream s;
        s << arr[i];
        mxlen = std::max(mxlen, s.str().length());
    }
    for (size_t i = 0; i < size; i++) {
        std::cout << std::setw(mxlen) << std::left << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void print(T* arr2d, int size) {
    print(arr2d, (size_t)size);
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

template<size_t size>
void print(const char (&arr)[size]) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i];
    }
    std::cout << "\n";
}