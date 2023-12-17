#pragma once
#include <vector>
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;

	void operator+=(const stats& rhs) {
		this->comparison_count += rhs.comparison_count;
		this->copy_count += rhs.copy_count;
	}

	stats operator+(const stats& rhs) {
		stats temp;
		temp.comparison_count = this->comparison_count + rhs.comparison_count;
		temp.copy_count = this->copy_count + rhs.copy_count;
		return temp;
	}
};

class MyClass {
private:
	int value;
public:
	MyClass() : value(0) {};
	MyClass(const int value) : value(value) {};
	int get_value() const {
		return this->value;
	}
	bool operator>(const MyClass& rhs) const {
		return this->value > rhs.value;
	}

	bool operator<(const MyClass& rhs) const {
		return this->value < rhs.value;
	}
};
//selection sort

template<typename T>
stats& SelectionSort(vector<T>& vec) {
	stats stat;
	int index;
	for (int i = 0; i < vec.size() - 1; i++) {
		index = i;
		for (int j = i + 1; j < vec.size(); j++) {
			stat.comparison_count += 1;
			if (vec[j] < vec[index]) index = j;
		}
		if (index != i) {
			swap(vec[i], vec[index]);
			stat.copy_count += 3;
		}
	}
	return stat;
}

//quick sort
template <typename T>
int partition(vector<T>& arr, int low, int high, stats& stat) {
	T pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		stat.comparison_count++;
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
			stat.copy_count += 3;
		}
	}
	swap(arr[i + 1], arr[high]);
	stat.copy_count += 3;
	return i + 1;
}

template <typename T>
stats Quicksort(vector<T>& arr, int low, int high) {
	stats stat;
	stat.comparison_count++;
	if (low < high) {
		int pi = partition(arr, low, high, stat);
		stat = stat + Quicksort(arr, low, pi - 1);
		stat = stat + Quicksort(arr, pi + 1, high);
	}
	return stat;
}

 //double merge sort

template <typename T>
stats merge(std::vector<T>& arr, int low, int mid, int high, stats &stat) {
	int n1 = mid - low + 1;
	int n2 = high - mid;

	std::vector<T> left(n1);
	std::vector<T> right(n2);

	for (int i = 0; i < n1; i++) {
		left[i] = arr[low + i];
		stat.comparison_count++;
		stat.copy_count++;
	}
	for (int j = 0; j < n2; j++) {
		right[j] = arr[mid + 1 + j];
		stat.comparison_count++;
		stat.copy_count++;
	}

	int i = 0, j = 0, k = low;
	while (i < n1 && j < n2) {
		stat.comparison_count++;
		if (left[i] < right[j]) { //!!!!
			arr[k] = left[i];
			stat.copy_count++;
			i++;
		}
		else {
			arr[k] = right[j];
			stat.copy_count++;
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = left[i];
		i++;
		k++;
		stat.comparison_count++;
		stat.copy_count++;
	}

	while (j < n2) {
		arr[k] = right[j];
		j++;
		k++;
		stat.comparison_count++;
		stat.copy_count++;
	}
	return stat;
}

template <typename T>
stats mergeSort(std::vector<T>& arr, int low, int high) {
	stats stat;
	if (low < high) {
		int mid = low + (high - low) / 2;
		stat = stat + mergeSort(arr, low, mid);
		stat = stat + mergeSort(arr, mid + 1, high);
		stat = stat + merge(arr, low, mid, high, stat);
	}
	return stat;
}



template <typename T>
vector<T> RandomVec(size_t size) {
	vector<T> vec(size);
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < size; ++i) {
		vec[i] = rand();
	}
	return vec;
}

template <typename T>
vector<T> SortedVec(size_t size) {
	vector<T> vec(size);
	for (size_t i = 0; i < size; ++i) {
		vec[i] = i;
	}
	return vec;
}

template <typename T>
vector<T> ReverseSortedVec(size_t size) {
	vector<T> vec(size);
	for (size_t i = 0; i < size; ++i) {
		vec[i] = size - i;
	}
	return vec;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T>& data) {
	for (size_t i = 0; i < data.size(); i++) {
		if (i != 0 && i % 10 == 0) {
			cout << endl;
		}
		out.width(4);
		out << data[i] << ' ';
	}
	out << endl;
	return out;
}

ostream& operator<<(ostream& out, stats& st) {
	out << "comparison_count = " << st.comparison_count << endl;
	out << "copy_count = " << st.copy_count << endl;
	return out;
}

ostream& operator<<(ostream& out, MyClass& me) {
	out << me.get_value();
	return out;
}

ofstream& operator<<(ofstream& out, stats& st) {
	out << st.comparison_count << " " << st.copy_count << '\n';
	return out;
}
