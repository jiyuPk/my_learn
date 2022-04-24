#include <iostream>
#include <vector>

using namespace std;
using i64 = long long;
i64 cache[6'000'001];
vector<i64> prime_numbers;

void calculate() {
	for (int i{ 2 }; i <= 5'000'001; i++) {
		if (!cache[i])
			prime_numbers.push_back(i);
		for (auto p : prime_numbers) {
			if (i * p >= 5'000'001)
				break;
			cache[i * p] = p;
			if (i % p == 0)
				break;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	calculate();

	int n;
	cin >> n;

	for (int i{ 0 }; i < n; i++) {
		i64 temp;
		cin >> temp;

		while (cache[temp]) {
			cout << cache[temp] << ' ';
			temp /= cache[temp];
		}

		cout << temp << '\n';
	}
}