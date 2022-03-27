#include <iostream>

using namespace std;

int divisor_number(int n)
{
    int result{0};
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            result++;
            if (i * i < n)
                result++;
        }
    }
    return result;
}

int main()
{
    int number;
    cin >> number;

    int value, result{0};
    for (int i{0}; i < number; i++)
    {
        cin >> value;
        int dn{divisor_number(value)};
        if (dn == 2)
        {
            result++;
        }
    }
    cout << result;
}