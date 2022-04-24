#include <iostream>

using namespace std;
using i64 = long long;

i64 cache[1'000'001];

void calculate() {
	for (int i{ 1 }; i <= 1000001; i++)
		for (int j = i; j <= 1000001; j += i)
			cache[j] += i;

	for (int i{ 2 }; i <= 1000001; i++)
		cache[i] += cache[i - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	calculate();

	int n;
	cin >> n;

	for (int i{ 0 }; i < n; i++) {
		int temp;
		cin >> temp;
		cout << cache[temp] << '\n';
	}
}
