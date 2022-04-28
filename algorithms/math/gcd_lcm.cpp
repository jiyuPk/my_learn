int gcd(int a, int b) {
	if (b == 0)
		return a;
	if (b == 1)
		return 1;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}
