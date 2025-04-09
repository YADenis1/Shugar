#pragma once
#include "templates.ipp"
#include "print.ipp"

/// <summary>
/// разделяет строку по на подстроки по элементу sep
/// </summary>
/// <param name="in">строка для разделения</param>
/// <param name="sep">элемент по которому будут разделять</param>
/// <returns>возвращает вектор подстрок</returns>
std::vector<std::string> split(std::string in, char sep);

/// <summary>
/// находит индекс элемента element в ДИНАМИЧЕКСКОМ массиве
/// </summary>
/// <param name="arr">динамиически массив</param>
/// <param name="size">размер массива</param>
/// <param name="element">элемент массива</param>
/// <returns>возвращает индекс элемента, или -1, если элемент не найден</returns>
template <typename T>
long long int find(const T* arr, size_t size, T element);

/// <summary>
/// находит индекс элемента element в СТАТИЧЕКСОМ массиве
/// </summary>
/// <param name="arr">массив</param>
/// <param name="element">элемент массива</param>
/// <returns>возвращает индекс элемента, или -1, если элемент не найден</returns>
template <typename T, size_t size>
long long int find(const T(&arr)[size], T element);

bool isPrime(long long int num);

long long int fact(int num);

template <typename T>
T randBetween(T from, T to);

std::string trim(std::string str);

std::string substring(std::string str, size_t from, size_t to);

template <typename T, typename U>
std::map<T, U> mergeMaps(std::map<T, U> map1, std::map<T, U> map2);

template <typename T>
std::vector<int> findAll(const T* arr, size_t size, T element);

template <typename T, size_t size>
std::vector<int> findAll(const T(&arr)[size], T element);

template <typename T>
int binFind(const T* arr, size_t size, T element);

template <typename T, size_t size>
int binFind(const T(&arr)[size], T element);

template <typename T>
T input(const std::string prom);

static void flushCinBuffer();

template <typename T, size_t rows, size_t cols>
void print(T(&array2d)[rows][cols]);

template <typename T>
void print(T* array, size_t size);

template <typename T, size_t size>
void print(T(&array)[size]);

template <typename T>
void print(const T** array2d, size_t rows, size_t cols);

template <typename T>
void print(T** array2d, int rows, int cols);

template <typename T>
void print(const T* arr, size_t size);

template <typename T>
void print(T* array2d, int size);

template <typename T>
void print(std::initializer_list<T> elements);

template <typename... T>
void print(T... args);

template<typename T>
void print(std::vector<T> vec);

template<typename T, typename U>
void print(std::map<T, U> mp);

template<typename T>
void print(std::set<T> st);

template <typename T>
T max(const T* arr, size_t size);

template <typename T, size_t size>
T max(const T(&arr)[size]);

template <typename T>
T min(const T* arr, size_t size);

template <typename T, size_t size>
T min(const T(&arr)[size]);

template <typename T>
void abs(T*& arr, size_t size);

template <typename T, size_t size>
void abs(T(&arr)[size]);

template <typename T>
void append(T*& array, size_t& size, T element);

template <typename T>
auto sum(const T* array, size_t size);

template <typename T, size_t size>
auto sum(const T(&arr)[size]);

template <typename T>
auto sum(std::initializer_list<T>);

template <typename... T>
auto sum(T... args);

static bool all(std::initializer_list<int> elements);

static bool all(std::initializer_list<bool> elements);

static bool all(std::initializer_list<size_t> elements);

static bool any(std::initializer_list<int> elements);

static bool any(std::initializer_list<bool> elements);

static bool any(std::initializer_list<size_t> elements);

template <typename T, size_t rows, size_t cols>
void fill(T(&array)[rows][cols], const T value);

template <typename T, size_t size>
void fill(T(&array)[size], const T value);

template <typename T>
void fill(T**& array, size_t rows, size_t cols, const T value);

template <typename T>
void fill(T*& array, size_t size, const T value);

template <typename T>
void transpose(T(&array), size_t Rows, size_t Cols);

template <typename T>
void transpose(T**& array, size_t rows, size_t cols);

template <typename size_t rows, typename size_t cols>
void fillRadnom(int(&array)[rows][cols], int from, int to);

void fillRadnom(int**& array, size_t rows, size_t cols, int from, int to);

template <typename size_t size>
void fillRadnom(int(&array)[size], int from, int to);

void fillRadnom(int*& array, size_t size, int from, int to);

template <typename T>
T** create2dArr(size_t, size_t, const T&);

template <typename T>
void free2dArr(T** array, size_t rows);

template <typename T>
T* createArr(size_t, const T&);

template <typename T>
void freeArr(T* arr);

template <typename T, size_t size>
void sortInclude(T(&arr)[size]);

template <typename T>
void sortInclude(T(*&arr), size_t size);

template<typename T, size_t size>
void reverse(T(&arr)[size]);

template<typename T>
void reverse(T*& arr, size_t size);

template<typename T, typename U>
T* getMapKeys(std::map<T, U> mp);

template<typename T, typename U>
void reverseMap(std::map<T, U> in, std::map<U, T>& out);

template<typename T, typename U>
std::map<U, T> reverseMap(std::map<T, U> in);

template<typename T, typename U>
U* getMapValues(std::map<T, U> mp);

template<typename T>
T* getVecValues(std::vector<T> vec);

std::string bin(int num);

template <typename T>
bool isUnique(const T* arr, size_t size);

template <typename T, size_t size>
bool isUnique(const T(&arr)[size]);

template <typename T>
T* concat(const T* arr1, size_t size1, const T* arr2, size_t size2);

template <typename T, size_t size1, size_t size2>
T* concat(const T(&arr1)[size1], const T(&arr2)[size2]);

template <typename T>
T** multiplyMatrix(T** mat1, size_t rows1, size_t cols1, T** mat2, size_t rows2, size_t cols2);

template <typename T, size_t rows1, size_t cols1, size_t rows2, size_t cols2>
T** multiplyMatrix(T(&arr1)[rows1][cols1], T(&arr2)[rows2][cols2]);

template <typename T>
std::string join(T* arr, size_t size, std::string sep);

template <typename T, size_t size>
std::string join(T(&arr)[size], std::string sep);

std::string join(std::vector<std::string>, std::string sep);

template <typename T>
bool contain(T* arr, size_t size, T element);

template <typename T, size_t size>
bool contain(T(&arr)[size], T element);

template <typename T, size_t size>
void fillRange(T(&arr)[size], T start, T end, T step);

template <typename T>
void fillRange(T* arr, size_t size, T start, T end, T step);

template <typename T>
T* range(T start, T end, T step);

int* range(int end);