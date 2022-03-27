#include <iostream>
#include <numeric>
#include <functional>

using namespace std;

template<typename It,
	typename T = typename iterator_traits<It>::value_type,
	typename Compare = typename function<bool(T, T)>>
	T min_element(It first, It last, Compare cmp = 
		function<bool(T, T)>{ [&](const T& a, const T& b) { return a < b; } }) {
	auto init = *first;
	return accumulate(++first, last, init, [&](const T& a, const T& b) {
		return cmp(b, a) ? b : a;
		});
}

int main() {
	int v[]{ 3, 1, 4, 1, 5, 9 };
	function<bool(int, int) >;
	auto result = min_element(cbegin(v), cend(v));
	std::cout << "min element at: " << result << "\n";

	cout << boolalpha;
	bool v1[]{ true,true,true,true };
	bool all_true = accumulate(cbegin(v1), cend(v1), true, logical_and<>{});
	cout << "all_true: " << all_true << "\n";
	bool some_true = accumulate(cbegin(v1), cend(v1), false, logical_or<>{});
	cout << "some_true: " << some_true << "\n";
}
