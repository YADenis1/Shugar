// Shugar.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <initializer_list>
#include <cstdarg>
#include <random>

std::string bin(int num) {
	std::string outRev = "";
	std::string out = "";
	while (num > 1) {
		outRev += std::to_string(num % 2);
		num = num / 2;
	}
	outRev += std::to_string(num);
	for (size_t i = std::size(outRev); i > 0; i--) {
		out = outRev[i];
	}
	return outRev;
}

static bool all(std::initializer_list<int> elements) {
	bool flag = true;
	for (int element : elements) {
		if (element == 0) flag = false;
	}
	return flag;
}

static bool all(std::initializer_list<bool> elements) {
	bool flag = true;
	for (bool element : elements) {
		if (element == false) flag = false;
	}
	return flag;
}

static bool all(std::initializer_list<size_t> elements) {
	return all(elements);
}

static bool any(std::initializer_list<int> elements) {
	bool flag = false;
	for (int element : elements) {
		if (element == 1) flag = true;
	}
	return flag;
}

static bool any(std::initializer_list<bool> elements) {
	bool flag = false;
	for (bool element : elements) {
		if (element == true) flag = true;
	}
	return flag;
}

static bool any(std::initializer_list<size_t> elements) {
	return any(elements);
}

static void flushCinBuffer() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::vector<std::string> split(std::string str, char sep) {
	std::vector<std::string> out;
	std::string substr = "";
	for (char element : str) {
		if (sep == element) {
			if (substr != "") {
				out.push_back(substr);
			}
			substr = "";
		}
		else {
			substr += element;
		}
	}
	return out;
}

bool isPrime(long long int num) {
	if (num <= 1) {
		return false;
	}
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

long long int fact(int num) {
	long long int out = 1;
	for (int i = 2; i <= num; i++) {
		out = out * i;
	}
	return out;
}

std::string substring(std::string str, size_t from, size_t to) {
	std::string out = "";
	for (size_t i = from; i < to; i++) {
		out = out + str[i];
	}
	return out;
}

std::string trim(std::string str) {
	size_t i = 0;
	size_t j = str.length()-1;
	while (str[i] == ' ') {
		i++;
	}
	while (str[j] == ' ') {
		j--;
	}
	return substring(str, i, j+1);
}