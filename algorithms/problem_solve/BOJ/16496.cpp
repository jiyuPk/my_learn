#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// input
	int N{};
	cin >> N;
	vector<string> list(N);

	for (auto& s : list)
		cin >> s;

	ranges::sort(list, [](const string& a, const string& b) {
		if (a + b > b + a) return true;
		else return false;
		});

	// output
	if (list[0] == "0")
		cout << "0" << endl;
	else
		for (const auto& elem : list)
			cout << elem;
}