#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int test_cases{};
	cin >> test_cases;

	for (int i{ 0 }; i < test_cases; i++) {
		int R{}, C{};
		cin >> R >> C;

		// solution
		vector<string>grid(2 * R + 1);
		for (int i{ 0 }; i < 2 * R + 1; i++) {
			string result;

			if (i % 2 == 0) {
				result += "+";
				for (int j{ 0 }; j < C; j++)
					result += "-+";
			}
			else {
				result += "|";
				for (int j{ 0 }; j < C; j++)
					result += ".|";
			}

			grid[i] = result;
		}

		grid[0][0] = '.';
		grid[0][1] = '.';
		grid[1][0] = '.';

		// output
		cout << "Case #" << i + 1 << ": " << endl;
		for (const auto& row : grid) {
			for (const auto& column : row)
				cout << column;
			cout << "\n";
		}
	}
}
