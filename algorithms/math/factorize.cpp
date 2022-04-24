#include <iostream>
#include <vector>

using namespace std;
using i64 = long long;

// vector<pair<prime_number, count of number>>
vector<pair<i64, int>> factorize(i64 n) {
	vector<pair<i64, int> > result;
	for (i64 i{ 2 }; i * i <= n; i++)
		if (n % i == 0) {
			int cnt{ 0 };

			while (n % i == 0) {
				cnt++; n /= i;
			}

			result.emplace_back(i, cnt);
		}

	if (n != 1)
		result.emplace_back(n, 1);
	return result;
}