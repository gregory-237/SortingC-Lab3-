#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
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

template<typename T>
int Partition(vector<T>& v, int start, int end, stats stat) {

	int pivot = end;
	int j = start;
	for (int i = start; i < end; ++i) {
		stat.comparison_count++;
		if (v[i] < v[pivot]) {
			swap(v[i], v[j]);
			++j;
			stat.copy_count += 3;
		}
	}
	swap(v[j], v[pivot]);
	stat.copy_count += 3;
	return j;
}

template<typename T>
stats& Quicksort(vector<T>& v, int start, int end) {
	stats stat;
	stat.comparison_count++;
	if (start < end) {
		int p = Partition(v, start, end, stat);
		stat = stat + Quicksort(v, start, p - 1);
		stat = stat + Quicksort(v, p + 1, end);
	}
	return stat;
}

// double merge sort

template<typename T>
stats merge(vector<T>& arr, int i, int j) {
	stats sort_stats;
	if (i + j >= arr.size()) {
		j = 1;
	}
	vector<T> right(arr.end() - j, arr.end());
	vector<T> left(arr.begin(), arr.begin() + i);
	sort_stats.copy_count += i;
	sort_stats.copy_count += j;
	int n1 = left.size();
	int n2 = right.size();
	int count_left = 0;
	int count_right = 0;
	arr.erase(arr.end() - j, arr.end());
	arr.erase(arr.begin(), arr.begin() + i);
	while (count_left < n1 && count_right < n2) {
		sort_stats.comparison_count += 1;
		if (left[left.size() - 1 - count_left] > right[count_right]) {
			arr.insert(arr.begin(), left[left.size() - 1 - count_left]);
			++count_left;
		}
		else {
			arr.insert(arr.begin(), right[count_right]);
			++count_right;
		}
	}
	while (count_left < n1) {
		sort_stats.comparison_count += 1;
		arr.insert(arr.begin(), left[left.size() - 1 - count_left]);
		++count_left;
	}
	while (count_right < n2) {
		sort_stats.comparison_count += 1;
		arr.insert(arr.begin(), right[count_right]);
		++count_right;
	}
	//cout << arr;
	return sort_stats;
}

template<typename T>
stats merge_sort(vector<T>& arr, int begin, int end) {
	stats sort_stats;
	int i_first = begin;
	int i_last = begin;
	int j_first = end;
	int j_last = end;
	while (i_last < end && arr[i_last] < arr[i_last + 1]) {
		sort_stats.comparison_count += 1;
		++i_last;
	}
	while (j_first > begin && arr[j_first] < arr[j_first - 1]) {
		sort_stats.comparison_count += 1;
		--j_first;
	}
	if (i_last == arr.size() - 1) {
		return sort_stats;
	}
	else {
		sort_stats += merge(arr, i_last + 1, j_last - j_first + 1);
		sort_stats += merge_sort(arr, 0, arr.size() - 1);
		return sort_stats;
	}
}

template<typename T>
stats merge_sort(vector<T> arr) {
	stats sort_stats;
	sort_stats += merge_sort(arr, 0, arr.size() - 1);
	cout << arr;
	return sort_stats;
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

