#include <iostream>

using namespace std;

bool is_prime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i{2}; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int first, last;
    cin >> first >> last;

    for (int i{first}; i <= last; i++)
    {
        if (is_prime(i))
        {
            cout << i << "\n";
        }
    }
}