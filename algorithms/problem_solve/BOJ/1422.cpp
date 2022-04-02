#include <iostream>
#include <deque>
#include <ranges>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// input
	int K{}, N{};
	cin >> K >> N;
	deque<string> list{};

	string biggest{};
	for (int i{ 0 }; i < K; i++) {
		string tmp;
		cin >> tmp;

		if (biggest.size() < tmp.size() || (biggest.size() == tmp.size() && biggest < tmp))
			biggest = tmp;

		list.push_back(tmp);
	}

	// solution
	for (int i{ K }; i < N; i++)
		list.push_back(biggest);

	ranges::sort(list, [](string a, string b) {
		if (a + b > b + a) return true;
		else return false;
		});

	// output
	for (const auto& elem : list)
		cout << elem;
}
