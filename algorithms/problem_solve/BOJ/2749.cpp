#include <iostream>

using namespace std;
using i64 = long long;

constexpr int m{ 1'000'000 };

// calculate the remainder of dividing the Nth Fibonacci number by m
// Remainder of the Nth Fibonacci % m equals the N%pth Fibonacci number % m

constexpr int p{ 15 * (m / 10) };
i64 a[p] = { 0,1 };

int main() {
	i64 n;
	cin >> n;

	for (int i = 2; i < p; i++)
		a[i] = (a[i - 1] + a[i - 2]) % m;

	cout << a[n % p];
}