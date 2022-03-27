#include <iostream>
#include <vector>

using namespace std;

using i64 = long long;

int main()
{

    i64 first, last;
    cin >> first >> last;

    i64 result{last - first + 1};
    vector<bool> vec(result, false);

    i64 i{2};
    for (i64 sq{0}; (sq = i * i) <= last; i++)
    {
        i64 n = first / sq;

        if (first % sq != 0)
        {
            ++n;
        }

        while (n * sq <= last)
        {
            if (vec[n * sq - first] == false)
            {
                vec[n * sq - first] = true;
                --result;
            }
            ++n;
        }
    }

    cout << result;
}