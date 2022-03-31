#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <algorithm>>

using namespace std;

class null_param
{
};

template <typename Sig, typename F>
class memoize_helper;

template <typename Result, typename... Args, typename F>
class memoize_helper<Result(Args...), F>
{
public:
    // Constructors
    template <typename Function>
    memoize_helper(Function &&f, null_param)
        : f(f) {}

    memoize_helper(const memoize_helper &other)
        : f(other.f) {}

    template <typename... InnerArgs>
    Result operator()(InnerArgs &&...args) const
    {
        const auto args_tuple{make_tuple(args...)};
        const auto cached{cache.find(args_tuple)};

        if (cached != cache.end())
        {
            return cached->second;
        }
        else
        {
            auto &&result{f(*this, forward<InnerArgs>(args)...)};
            cache[args_tuple] = result;
            return result;
        }
    }

private:
    using function_type = F;
    using args_tuple_type = tuple<decay_t<Args>...>;

    function_type f;

    mutable map<args_tuple_type, Result> cache;
};

template <typename Sig, typename F>
memoize_helper<Sig, decay_t<F>>
make_memoized(F &&f)
{
    return {forward<F>(f), null_param{}};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    auto lev_memo{make_memoized<int(int, int)>(
        [&](auto &lev, int m, int n)
        {
            return m == 0   ? n
                   : n == 0 ? m
                            : min({lev(m - 1, n) + 1,
                                   lev(m, n - 1) + 1,
                                   lev(m - 1, n - 1) + (a[m - 1] != b[n - 1])});
        })};

    cout << lev_memo(a.size(), b.size());
}
