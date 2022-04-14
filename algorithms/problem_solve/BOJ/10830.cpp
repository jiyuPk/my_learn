#include <iostream>
#include <functional>
#include <vector>

using namespace std;

using i64 = long long int;
using matrix_t = vector<vector<long long int>>;

matrix_t operator* (const matrix_t& m1, const matrix_t& m2) {
	auto size = m1.size();
	matrix_t result(size, vector<i64>(size));

	for (int i{ 0 }; i < size; i++)
		for (int j{ 0 }; j < size; j++) {
			for (int f{ 0 }; f < size; f++)
				result[i][j] += m1[i][f] * m2[f][j];
			result[i][j] %= 1000;
		}

	return result;
}

int main() {
	i64 n, b;
	cin >> n >> b;

	// input
	matrix_t matrix_1(n, vector<i64>(n));

	for (auto& row : matrix_1)
		for (auto& cell : row)
			cin >> cell;

	// solve
	function<matrix_t(matrix_t&, i64)> pow = [&pow](matrix_t& mx, i64 m) {
		auto size{ mx.size() };
		matrix_t result(size, vector<i64>(size));
		for (int i{ 0 }; i < size; i++)
			result[i][i] = 1;

		if (m == 0)
			return result;

		if (m % 2 == 1)
			return pow(mx, m - 1) * mx;

		matrix_t half = pow(mx, m / 2);

		return half * half;
	};

	auto result{ pow(matrix_1,b) };

	// output
	for (auto& row : result) {
		for (auto& cell : row)
			cout << cell % 1000 << ' ';
		cout << '\n';
	}
}