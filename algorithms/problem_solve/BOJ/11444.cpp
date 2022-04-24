#include <iostream>
#include <vector>

using namespace std;
using i64 = long long;
using matrix_t = vector<vector<i64>>;

constexpr i64 m{ 1'000'000'007 };

matrix_t operator* (const matrix_t& m1, const matrix_t& m2) {
	matrix_t result(2, vector<i64>(2));

	for (int i{ 0 }; i < 2; i++)
		for (int j{ 0 }; j < 2; j++) {
			for (int k{ 0 }; k < 2; k++)
				result[i][j] += m1[i][k] * m2[k][j];
			result[i][j] %= m;
		}

	return result;
}

int main() {
	i64 n;
	cin >> n;

	matrix_t matrix_1{ {0,1},{1,0} };
	matrix_t matrix_2{ {1,1},{1,0} };;
	
	while (n > 0) {
		if (n % 2 == 1)
			matrix_1 = matrix_1 * matrix_2;
		matrix_2 = matrix_2 * matrix_2;
		n /= 2;
	}

	cout << matrix_1[0][0];
}