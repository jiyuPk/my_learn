#include <iostream>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

auto get_input()
{
    int n{};
    cin >> n;

    vector<vector<int>> list(n, vector<int>(n));

    for (int i{0}; i < n; ++i)
    {
        for (int j{0}; j < n; ++j)
        {
            cin >> list[i][j];
        }
    }

    return make_tuple(n, list);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto [n, distance_list]{get_input()};
    vector<vector<int>> memoization(n, vector<int>(1 << n));

    function<int(int, int)> find_path = [&](int cur_city, int visited)
    {
        int result{memoization[cur_city][visited]};
        if (result != 0)
        {
            return result;
        }
        if (visited == ((1 << n) - 1))
        {
            if (distance_list[cur_city][0] != 0)
                return distance_list[cur_city][0];
            return 987654321;
        }

        result = 987654321;
        for (int next = 0; next < n; next++)
        {
            if (distance_list[cur_city][next] == 0)
            {
                continue;
            }
            if (visited & (1 << next))
            {
                continue;
            }
            result = min(result, distance_list[cur_city][next] + find_path(next, visited | 1 << next));
        }
        memoization[cur_city][visited] = result;
        return result;
    };

    cout << find_path(0, 1);
}