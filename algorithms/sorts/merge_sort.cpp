#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void merge(vector<int>& vec, int left, int mid, int right) {
	vector<int> tmp(right - left + 1);

	int i{ left };
	int j{ mid + 1 };
	int k{ 0 };

	// merge
	while (i <= mid && j <= right)
		if (vec[i] < vec[j])
			tmp[k++] = vec[i++];
		else
			tmp[k++] = vec[j++];

	// copy the rest
	while (i <= mid)
		tmp[k++] = vec[i++];
	while (j <= right)
		tmp[k++] = vec[j++];

	// copy back
	for (int i{ 0 }; i < tmp.size(); ++i)
		vec[left + i] = tmp[i];
}

void merge_sort(vector<int>& vec, int left, int right) {
	if (left < right) {
		int mid{ (left + right) / 2 };		// Divide
		merge_sort(vec, left, mid);			// Conquer
		merge_sort(vec, mid + 1, right);	// Conquer
		merge(vec, left, mid, right);		// Combine
	}
}

auto get_input() {
	int input_amount{};

	cin >> input_amount;
	vector<int> vec(input_amount);

	for (auto& elem : vec)
		cin >> elem;

	return make_tuple(vec, input_amount);
}

int main() {
	auto [vec, n] {get_input()};

	merge_sort(vec, 0, n - 1);

	for (auto elem : vec)
		cout << elem << "\n";
}