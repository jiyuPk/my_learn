#include <cstdio>
#include <functional>
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;
using llu = long long unsigned;

class fib_cache
{
public:
    llu operator[](llu n) const
    {
        return n == size - 1 ? last : 
               n == size - 2 ? previous : 0;
    }

    void push_back(llu value)
    {
        size++;
        previous = last;
        last = value;
    }

    llu previous = 0;
    llu last = 1;
    size_t size = 2;
};

int main()
{
    fib_cache cache;
    function<llu(llu)> fib_with_cache = [&](llu n) { // O(n)
        if (cache.size > n)
        {
            return cache[n];
        }
        else
        {
            cache.push_back(fib_with_cache(n - 1) + fib_with_cache(n - 2));
            return cache.last;
        }
    };

    function<llu(llu)> fib = [&](llu n) { // O(n^2)
        return n == 0 ? 0 : 
               n == 1 ? 1 : 
               fib(n - 1) + fib(n - 2);
    };

    unsigned i;
    scanf("%d", &i);

    system_clock::time_point start = system_clock::now();

    printf("%llu \n", fib_with_cache(i));

    system_clock::time_point end = system_clock::now();
    cout << duration_cast<milliseconds>(end - start).count() << " ms\n";
}
