#include <cstdio>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>


using namespace std;

// Insert T in proper position
template <typename T>
list<T> ascending_sort(list<T> lst, T i)
{
    // Insert first number
    if (lst.empty())
    {
        lst.push_back(i);
        return lst;
    }

    // find proper position for i
    bool inserted = false;
    for (auto iter = lst.begin(); iter != lst.end(); iter++)
    {
        if (*iter >= i)
        {
            lst.insert(iter, i);
            inserted = true;
            break;
        }
    }

    // if i is biggest number, push back
    if (inserted != true)
    {
        lst.push_back(i);
    }

    return lst;
}

template <typename T>
list<T> insertion_sort1(vector<T> vec)
{
    list<T> result;
    result = accumulate(
        vec.cbegin(),
        vec.cend(),
        result,
        ascending_sort<T>);
    return result;
}

void insertion_sort2(vector<int> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        auto const insertion_point = upper_bound(vec.begin(), it, *it);

        rotate(insertion_point, it, it + 1);
    }
}

vector<int> get_input()
{
    int input_amount{};
    scanf("%d", &input_amount);
    vector<int> vec(input_amount);
    for (int i = 0; i < input_amount; i++)
    {
        int input{};
        scanf("%d", &input);
        vec[i] = input;
    }

    return vec;
}
int main()
{
    vector<int> vec = get_input();

    auto result = insertion_sort1(vec);

    insertion_sort2(vec);

    for (auto elem : result)
    {
        printf("%d \n", elem);
    }

    for (auto elem : vec)
    {
        printf("%d \n", elem);
    }
}