#ifndef TESTS_H
#define TESTS_H


#include <vector>
#include <algorithm>

class Tests {
public:
	template<typename T>
	static T min_t(T a, T b) {
		return (a < b) ? a : b;
	}


	template<typename T>
	static void sort_t(std::vector<T>& arr) {
		for (size_t i = 0; i + 1 < arr.size(); ++i) {
			for (size_t j = 0; j + 1 < arr.size(); ++j) {
				if (arr[j] < arr[j + 1]) std::swap(arr[j], arr[j + 1]);
			}
		}
	}


	template<typename T>
	static T sum_t(const std::vector<T>& arr) {
		T s = 0;
		for (T x : arr) {
			if (x > 0) s += x;
		}
		return s;
	}
};


#endif