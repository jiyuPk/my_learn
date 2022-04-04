#include <iostream>
#include <queue>
#include <concepts>
#include <utility>

using namespace std;

template <typename T>
bool less_than(T a, T b) {
	return a < b;
}

template <typename T>
bool greater_than(T a, T b) {
	return a > b;
}

template <typename T, auto Predicate = less_than<T>>
bool and_operation(T a, same_as<T> auto... args) {
	// if invalid return true
	return (...&& Predicate(a, args));
}

template <typename T, auto Predicate = less_than<T>>
bool or_operation(T a, same_as<T> auto... args) {
	// if invalid return false
	return (... || Predicate(a, args));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << or_operation(5) << endl; 
}