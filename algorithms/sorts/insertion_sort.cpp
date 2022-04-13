#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>

using namespace std;

// Insert T in proper position
template <typename T>
list<T> ascending_sort(list<T> lst, T i) {
	// Insert first number
	if (lst.empty()) {
		lst.push_back(i);
		return lst;
	}

	// find proper position for i
	bool inserted = false;
	for (auto iter = lst.begin(); iter != lst.end(); iter++)
		if (*iter >= i) {
			lst.insert(iter, i);
			inserted = true;
			break;
		}

	// if i is biggest number, push back
	if (inserted != true)
		lst.push_back(i);

	return lst;
}

template <typename T>
list<T> insertion_sort1(vector<T> vec) {
	list<T> result;
	result = accumulate(
		     vec.cbegin(),
		     vec.cend(),
		     result,
		     ascending_sort<T>);
	
	return result;
}

void insertion_sort2(vector<int>& vec) {
	for (auto it = vec.begin(); it != vec.end(); it++) {
		auto const insertion_point = upper_bound(vec.begin(), it, *it);
		rotate(insertion_point, it, it + 1);
	}
}

void insertion_sort3(vector<int>& vec) {
	for (int i{ 0 }; i < vec.size(); ++i) {
		const int key = vec[i];
		int j{ i - 1 };
		while (j >= 0 && vec[j] > key) {
			vec[j + 1] = vec[j];
			--j;
		}
		vec[j + 1] = key;
	}
}


vector<int> get_input() {
	int input_amount{};

	cin >> input_amount;
	vector<int> vec(input_amount);

	for (auto& elem : vec)
		cin >> elem;

	return vec;
}

int main() {
	vector<int> vec = get_input();

	auto result = insertion_sort1(vec);

	insertion_sort2(vec);

	for (auto elem : result)
		cout << elem << "\n";

	for (auto elem : vec)
		cout << elem << "\n";
}