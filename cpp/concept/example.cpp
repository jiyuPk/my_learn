#include <iostream>
#include <string>
using namespace std;

template <typename P, typename... Types>
concept all_same = ( same_as<P, Types> && ... );

template <typename P, typename... Types>
concept all_different = (!same_as<P, Types> && ... );

template <typename P, typename... Types>
concept partially_different = (!all_same<P, Types...> && !all_different<P, Types...>);

template <typename P, typename... Types>
    requires all_same<P, Types...>
auto sum(P p, Types... args) {
    cout << "All types are the same !" << endl;
    return (p + ... + args);
}

template <typename P, typename... Types>
    requires all_different<P, Types...>
auto sum(P p, Types... args) {
    cout << "All different types !" << endl;
    return (p + ... + args);
}

template <typename P, typename... Types>
    requires partially_different<P, Types...>
auto sum(P p, Types... args) {
   cout << "Partially different types !" << endl;
    return (p + ... + args);
}


int main() {
    sum(1, 2, 3, 4, 5);
    sum(1, 2.0, 2.1f);
	sum(1, 2, 3, 4, 5.f);

}