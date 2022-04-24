#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

using i64 = long long;

// returns tuple{gcd, x, y}
// gdc(a, b)
// ax + by = gdc(a, b)
tuple<i64, i64, i64> extended_euclidean(i64 a, i64 b) {
	if (b == 0)
		return { a, 1, 0 };
	auto [gcd, x, y] {extended_euclidean(b, a % b)};
	return { gcd, y, x - (a / b) * y };
}

i64 mod_inverse(i64 a, i64 m) {
	auto [gcd, x, y] {extended_euclidean(a, m)};
	return (x % m + m) % m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	i64 n, a;
	cin >> n >> a;

	// (a + b) mod n = 0
	const i64 b = n - a;

	cout << b << " ";

	// (a * c) mod n = 1
	// ac + ny = 1
	auto [g, x, y] {extended_euclidean(a, n)};

	if (g != 1) {
		cout << -1;
		return 0;
	}

	cout << mod_inverse(a, n);
}