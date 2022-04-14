#include <iostream>
#include <vector>

using namespace std;

using matrix_t = vector<vector<int>>;

int main() { 
	using matrix_t = vector<vector<int>>;
	
	int n, m;
	cin >> n >> m;
	
	matrix_t matrix_1(n, vector<int>(m));
	
	for (auto& row : matrix_1)
		for (auto& cell : row)
			cin >> cell;
	
	int k;
	cin >> m >> k;
	matrix_t matrix_2(m, vector<int>(k));

	for (auto& row : matrix_2)
		for (auto& cell : row)
			cin >> cell;

	auto add_matrix = [&]() {
		for (int i{ 0 }; i < n; i++)
			for (int j{ 0 }; j < m; j++)
				matrix_1[i][j] += matrix_2[i][j];
	};

	//add_matrix();

	
	auto mul_matrix = [&]() {
		matrix_t result(n, vector<int>(k));
		for (int i{ 0 }; i < n; i++)
			for (int j{ 0 }; j < k; j++) 
				for (int f{ 0 }; f < m; f++)
					result[i][j] += matrix_1[i][f] * matrix_2[f][j];
	
		return result;
	};

	auto result{ mul_matrix() };

	for (auto& row : result) {
		for (auto& cell : row)
			cout << cell << ' ';
		cout << '\n';
	}
}