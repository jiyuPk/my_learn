#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int test_cases{};
	cin >> test_cases;
	
	for (int i{}; i < test_cases; i++) {
		// input
		int N{};
		cin >> N;

		int* arr = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		
		sort(arr, arr+N);
		
		// solution
		int result{0};
		for (int i{0}; i < N; i++) {
			if (arr[i] > result) {
				++result;
			}
		}
		
		// output
		cout << "Case #" << i + 1 << ": " << result << "\n";
	}
}