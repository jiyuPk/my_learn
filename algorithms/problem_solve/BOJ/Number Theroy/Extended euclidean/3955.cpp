#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

using i64 = long long;

i64 gcd(i64 a, i64 b) {
	return b == 0 ? a : gcd(b, a % b);
}

// returns tuple{gcd, x, y}
// gdc(a, b)
// ax + by = gdc(a, b)
tuple<i64, i64, i64> extended_euclidean(i64 a, i64 b) {
	if (b == 0)
		return { a, 1, 0 };
	auto [gcd, x, y] {extended_euclidean(b, a % b)};
	return { gcd, y, x - (a / b) * y };
}

i64 ceil(i64 a, i64 b) {
	if (a > 0)
		return (a + b - 1) / b;
	return a / b;
}

// kx + 1 = cy
// kx + cy = 1 | x > 0 | y < 0

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		i64 k, c;
		cin >> k >> c;

		auto [gcd, x, y] {extended_euclidean(k, c)};

		if (gcd != 1) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		const i64 i{ min(ceil(-x, c), ceil(y, k)) - 1 };

		if (y - 1e9 > i * k) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << y - i * k << '\n';
	}
}