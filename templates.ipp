#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

template <typename T>
T input(const std::string prom = "") {
    T param;
    if (!prom.empty()) {
        std::cout << prom;
    }
    while (!(std::cin >> param)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl << "Input error, try again >> ";
    }
    return param;
}

template <typename T>
int binFind(const T* arr, size_t size, T element) {
    size_t l = 0, r = size, mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (arr[mid] == element) {
            size_t it = mid;
            while (it>0 && element == arr[it-1]) {
                it--;
            }
            return it;
        }
        else if (arr[mid] < element) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return -1;
}

template <typename T, size_t size>
int binFind(const T (&arr)[size], T element) {
    size_t l = 0, r = size, mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (arr[mid] == element) {
            size_t it = mid;
            while (it > 0 && element == arr[it-1]) {
                it--;
            }
            return it;
        }
        else if (arr[mid] < element) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return -1;
}

template <typename T>
long long int find(const T* arr, size_t size, T element) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

template <typename T, size_t size>
long long int find(const T(&arr)[size], T element) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

template <typename T>
std::vector<int> findAll(const T* arr, size_t size, T element) {
    std::vector<int> out;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == element) {
            out.push_back(i);
        }
    }
    return out;
}

template <typename T, size_t size>
std::vector<int> findAll(const T(&arr)[size], T element) {
    std::vector<int> out;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == element) {
            out.push_back(i);
        }
    }
    return out;
}

template <typename T>
T max(const T* arr, size_t size) {
    T mx = arr[0];
    for (size_t i = 1; i < size; i++) {
        mx = std::max(arr[i], mx);
    }
    return mx;
}

template <typename T, size_t size>
T max(const T(&arr)[size]) {
    T mx = arr[0];
    for (size_t i = 0; i < size; i++) {
        mx = std::max(mx, arr[i]);
    }
    return mx;
}

template <typename T>
T min(const T* arr, size_t size) {
    T mn = arr[0];
    for (size_t i = 1; i < size; i++) {
        mn = std::min(arr[i], mn);
    }
    return mn;
}

template <typename T, size_t size>
T min(const T(&arr)[size]) {
    T mn = arr[0];
    for (size_t i = 0; i < size; i++) {
        mn = std::min(mn, arr[i]);
    }
    return mn;
}


template <typename T>
void abs(T*& arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        arr[i] = std::abs(arr[i]);
    }
}

template <typename T, size_t size>
void abs(T(&arr)[size]) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = std::abs(arr[i]);
    }
}

template <typename T>
void append(T*& arr, size_t& size, T element) {
    T* newArr = new int[size + 1];
    for (size_t i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = element;
    size++;
    delete[] arr;
    arr = newArr;
}

template <typename T, size_t size>
auto sum(const T(&arr)[size], bool(*filter)(T element) = nullptr) {
    T out = 0;
    for (size_t i = 0; i < size; i++) {
        if(!filter || filter(arr[i])){
            out += arr[i];
        }
    }
    return out;
}


template <typename T>
auto sum(const T* arr, size_t size, bool(*filter)(T element) = nullptr) {
    T out = 0;
    for (size_t i = 0; i < size; i++) {
        if (!filter || filter(arr[i])) {
            out += arr[i];
        }
    }
    return out;
}


template <typename T>
auto sum(std::initializer_list<T> elements) {
    T out = 0;
    for (T element : elements) {
        out += element;
    }
    return out;
}

template <typename... T>
auto sum(T... args) {
    return(0 + ... + args);
}

template <typename T, size_t size>
double avg(const T(&arr)[size]) {
    return(1. * sum(arr) / size);
}

template <typename T>
double avg(const T* arr, size_t size) {
    return(1. * sum(arr, size) / size);
}


template <typename T, size_t rows, size_t cols>
void fill(T(&arr)[rows][cols], const T value) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            arr[i][j] = value;
        }
    }
}

template <typename T>
void fill(T**& arr, size_t rows, size_t cols, T value) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            arr[i][j] = value;
        }
    }
}

template <typename T, size_t size>
void fill(T(&arr)[size], const T value) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = value;
    }
}

template <typename T>
void fill(T*& arr, size_t size, const T value) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = value;
    }
}

template <typename T>
void transpose(T(&arr), size_t Rows, size_t Cols) {
    for (size_t i = 0; i < Rows; i++) {
        for (size_t j = i; j < Cols; j++) {
            std::swap(arr[i][j], arr[j][i]);
        }
    }
}

template <typename T>
void transpose(T**& arr, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = i; j < cols; j++) {
            std::swap(arr[i][j], arr[j][i]);
        }
    }
}

template <typename size_t rows, typename size_t cols>
void fillRadnom(int(&arr)[rows][cols], int from, int to) {
    std::srand(time(NULL));
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            int value = std::rand() % (to - from) + from;
            arr[i][j] = value;
        }
    }
}

void fillRadnom(int**& arr, size_t rows, size_t cols, int from, int to) {
    std::srand(time(NULL));
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            int value = std::rand() % (to - from) + from;
            arr[i][j] = value;
        }
    }
}

template <typename size_t size>
void fillRadnom(int(&arr)[size], int from, int to) {
    std::srand(time(NULL));
    for (size_t j = 0; j < size; j++) {
        int value = std::rand() % (to - from) + from;
        arr[j] = value;
    }
}

void fillRadnom(int*& arr, size_t size, int from, int to) {
    std::srand(time(NULL));
    for (size_t j = 0; j < size; j++) {
        int value = std::rand() % (to - from) + from;
        arr[j] = value;
    }
}

template <typename T>
T** create2dArr(size_t rows, size_t cols, const T& value = T()) {
    T** arr = new T * [rows];
    for (size_t i = 0; i < rows; i++) {
        arr[i] = new T[cols];
        for (size_t j = 0; j < cols; j++) {
            arr[i][j] = value;
        }
    }
    return arr;
}

template <typename T>
void free2dArr(T** arr, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

template <typename T>
T* createArr(size_t size, const T& value = T()) {
    T* arr = new T[size];
    for (size_t i = 0; i < size; i++) {
        arr[i] = value;
    }
    return arr;
}

template <typename T>
void freeArr(T* arr) {
    delete[] arr;
}

template <typename T, size_t size>
void sortSwap(T(&arr)[size]) {
    for (size_t n = 0; n < size - 1; n++) {
        T mn = arr[n];
        size_t idx = 0;
        for (size_t c = n + 1; c < size; c++) {
            if (arr[c] < mn) {
                mn = arr[c];
                idx = c;
            }
        }
        if (idx != 0) {
            std::swap(arr[idx], arr[n]);
        }
    }
}

template <typename T>
void sortSwap(T(*&arr), size_t size) {
    for (size_t n = 0; n < size - 1; n++) {
        T mn = arr[n];
        size_t idx = 0;
        for (size_t c = n + 1; c < size; c++) {
            if (arr[c] < mn) {
                mn = arr[c];
                idx = c;
            }
        }
        if (idx != 0) {
            std::swap(arr[idx], arr[n]);
        }
    }
}

template <typename T>
void sortCount(T*& arr, size_t arrSize) {
    T mx = arr[0], mn = arr[0];
    for (size_t i = 1; i < arrSize; i++) {
        mx = std::max(mx, arr[i]);
        mn = std::min(mn, arr[i]);
    }

    const int range = mx - mn + 1;

    T* count = new int[range]();

    for (size_t i = 0; i < arrSize; i++) {
        count[arr[i] - mn]++;
    }
    size_t index = 0;
    for (size_t i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index] = i + mn;
            index++;
            count[i]--;
        }
    }
    delete[] count;
}

template <typename T, size_t size>
void sortCount(T(&arr)[size]) {
    T mx = arr[0], mn = arr[0];
    for (size_t i = 1; i < size; i++) {
        mx = std::max(mx, arr[i]);
        mn = std::min(mn, arr[i]);
    }

    const int range = mx - mn + 1;

    T* count = new int[range]();

    for (size_t i = 0; i < size; i++) {
        count[arr[i] - mn]++;
    }
    size_t index = 0;
    for (size_t i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index] = i + mn;
            index++;
            count[i]--;
        }
    }
    delete[] count;
}

template <typename T>
void sortQuick(T*& arr, size_t l, size_t r) {
    if (l >= r) return;
    T midEl = arr[(l + r) / 2];
    size_t i = l, j = r;
    while (i <= j) {
        while (arr[i] < midEl) {
            i++;
        }
        while (arr[j] > midEl) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i++], arr[j--]);
        }
    }
    sortQuick(arr, l, j);
    sortQuick(arr, i, r);
}

template <typename T, size_t size>
void sortQuick(T(&arr)[size], size_t l, size_t r) {
    if (l >= r) return;
    T midEl = arr[(l + r) / 2];
    size_t i = l, j = r;
    while (i <= j) {
        while (arr[i] < midEl) {
            i++;
        }
        while (arr[j] > midEl) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i++], arr[j--]);
        }
    }
    sortQuick(arr, l, j);
    sortQuick(arr, i, r);
}

template <typename T, size_t size, size_t prirSize>
void sortShell(T(&arr)[size], size_t(&prirArr)[prirSize]) {
    for (size_t gap : prirArr) {
        std::cout << "\n";
        for (size_t i = gap; i < size; i++) {
            T temp = arr[i];
            size_t j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template <typename T, size_t prirSize>
void sortShell(T*& arr, size_t size, size_t(&prirArr)[prirSize]) {
    for (size_t gap : prirArr) {
        for (size_t i = gap; i < size; i++) {
            T temp = arr[i];
            size_t j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template<typename T, size_t size>
void reverse(T(&arr)[size]) {
    for (size_t i = 0; i < size / 2; i++) {
        std::swap(arr[i], arr[size - i]);
    }
}

template<typename T>
void reverse(T*& arr, size_t size) {
    for (size_t i = 0; i < size / 2; i++) {
        std::swap(arr[i], arr[size - i - 1]);
    }
}

template<typename T, typename U>
void reverseMap(std::map<T, U> in, std::map<U, T>& out) {
    for (const auto& [k, v] : in) {
        out[v] = k;
    }
}

template<typename T, typename U>
std::map<U, T> reverseMap(std::map<T, U> in) {
    std::map<U, T> out;
    for (const auto& [k, v] : in) {
        out[v] = k;
    }
    return out;
}

template<typename T, typename U>
T* getMapKeys(std::map<T, U> mp) {
    T* out = new T[mp.size() + 1];
    size_t cnt = 0;
    for (const auto& [k, v] : mp) {
        out[cnt] = k;
        cnt++;
    }
    return out;
}

template<typename T, typename U>
U* getMapValues(std::map<T, U> mp) {
    U* out = new U[mp.size() + 1];
    size_t cnt = 0;
    for (const auto& [k, v] : mp) {
        out[cnt] = v;
        cnt++;
    }
    return out;
}

template<typename T, typename U>
std::map<T, U> mergeMaps(std::map<T, U> map1, std::map<T, U> map2) {
    std::map out = map1;
    for (const auto& [k, v] : map2) {
        out[k] = v;
    }
    return out;
}

template<typename T>
T* getVecValues(std::vector<T> vec) {
    T* out = new T[vec.size() + 1];
    size_t cnt = 0;
    for (const auto element : vec) {
        out[cnt] = element;
        cnt++;
    }
    return out;
}

template <typename T>
bool isUnique(const T* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}

template <typename T, size_t size>
bool isUnique(const T(&arr)[size]) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
T* concat(const T* arr1, size_t size1, const T* arr2, size_t size2) {
    T* result = new T[size1 + size2];
    for (size_t i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }
    for (size_t i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }
    return result;
}

template <typename T, size_t size1, size_t size2>
T* concat(const T(&arr1)[size1], const T(&arr2)[size2]) {
    T* result = new T[size1 + size2];
    for (size_t i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }
    for (size_t i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }
    return result;
}

template <typename T>
T** multiplyMatrix(T** arr1, size_t rows1, size_t cols1, T** arr2, size_t rows2, size_t cols2) {
    if (cols1 != rows2) {
        throw std::invalid_argument("Impossible to multiply Matrix: cols1 != rows2.");
    }
    T** result = create2dArr<T>(rows1, cols2, 0);
    for (size_t i = 0; i < rows1; i++) {
        for (size_t j = 0; j < cols2; j++) {
            for (size_t k = 0; k < cols1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return result;
}

template <typename T, size_t rows1, size_t cols1, size_t rows2, size_t cols2>
T** multiplyMatrix(T(&arr1)[rows1][cols1], T(&arr2)[rows2][cols2]) {
    if (cols1 != rows2) {
        throw std::invalid_argument("Impossible to multiply Matrix: cols1 != rows2.");
    }
    T** result = create2dArr<T>(rows1, cols2, 0);
    for (size_t i = 0; i < rows1; i++) {
        for (size_t j = 0; j < cols2; j++) {
            for (size_t k = 0; k < cols1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return result;
}

template <typename T>
std::string join(T* arr, size_t size, std::string sep) {
    if (size == 0) {
        return "";
    }
    std::ostringstream out;
    for (size_t i = 0; i < size; i++) {
        out << arr[i] << sep;
    }
    return out.str();
}

template <typename T, size_t size>
std::string join(T(&arr)[size], std::string sep) {
    if (size == 0) {
        return "";
    }
    std::ostringstream out;
    for (size_t i = 0; i < size; i++) {
        out << arr[i] << sep;
    }
    return out.str();
}

template <typename T>
std::string join(std::vector<std::string> vec, std::string sep) {
    if (vec.empty()) {
        return "";
    }
    std::ostringstream out;
    for (std::string el : vec) {
        out << el << sep;
    }
    return out.str();
}

template <typename T>
bool contain(T* arr, size_t size, T element) {
    return !(find(arr, size, element) == -1);
}

template <typename T, size_t size>
bool contain(T(&arr)[size], T element) {
    return !(find(arr, element) == -1);
}

template <typename T, size_t size>
void fillRange(T(&arr)[size], T start, T end, T step = 1) {
    size_t cycles = (end - start) / step;
    for (size_t i = 0; i < cycles; i++) {
        arr[i] = start + i * step;
        if (i > size) {
            break;
        }
    }
}

template <typename T>
void fillRange(T* arr, size_t size, T start, T end, T step = 1) {
    size_t cycles = (end - start) / step;
    for (size_t i = 0; i < cycles; i++) {
        arr[i] = start + i * step;
        if (i > size) {
            break;
        }
    }
}

template <typename T>
T* range(T start, T end, T step = 1) {
    size_t size = (end - start) / step;
    T* out = new T[size];
    for (size_t i = 0; i < size; i++) {
        out[i] = start + step * i;
    }
    return out;
}

int* range(int end) {
    int step = abs(end) / end;
    return range(0, end, step);
}

template <typename T>
T randBetween(T from, T to) {
    srand(time(NULL));
    return rand() % (to - from) + from;
}