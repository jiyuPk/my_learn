using i64 = long long int;

i64 fast_pow(i64 a, int n) {
	if (n == 0) return 1;

	if (n % 2 == 1)
		return fast_pow(a, n - 1) * a;

	i64 half = fast_pow(a, n / 2);

	return half * half;
}