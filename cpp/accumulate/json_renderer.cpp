#include <iostream>
#include <map>
#include <variant>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <utility>
#include <cassert>

using namespace std;

struct JSON_wrapper;
using JSON_array = vector<JSON_wrapper>;
using JSON_object = map<string, JSON_wrapper>;
using JSON_value = variant<bool, double, string, nullptr_t, JSON_array, JSON_object>;

struct JSON_wrapper
{
    JSON_value value;
    operator JSON_value &() { return value; }
    operator const JSON_value &() const { return value; }
};

template <typename It,
          typename T = typename iterator_traits<It>::value_type,
          typename Fn>
string join(It first, It last, string insert, Fn fn)
{
    return accumulate(first, last, string{}, [&](string result, T value)
                      {
		string str{ fn(value) };

		if (result.size() == 0) {
			return result + str;
		}

		return result + insert + str; });
}
template <size_t N, size_t Max>
struct apply_at
{
    template <typename R, typename T, typename F, typename... Fs>
    static auto apply(T &&t, size_t n, F &&f, Fs &&...fs)
    {
        if (n == N)
        {
            return forward<F>(f)(get<N>(forward<T>(t)));
        }
        else
        {
            return apply_at<N + 1, Max>::template apply<R, T, Fs...>(
                forward<T>(t),
                n,
                forward<Fs>(fs)...);
        }
    }
};

template <size_t Max>
struct apply_at<Max, Max>
{
    template <typename R, typename T, typename... Fs>
    static auto apply(T t, size_t n, Fs... fs)
    {
        assert("Variant index out of range" && false);
        return R{};
    }
};

template <typename T, typename F, typename... Fs>
static auto fold_at(T &&t, size_t n, F &&f, Fs &&...fs)
{
    using R = decltype(f(get<0>(t)));
    return apply_at<0, sizeof...(Fs) + 1>::template apply<R, T, F, Fs...>(
        forward<T>(t),
        n,
        forward<F>(f),
        forward<Fs>(fs)...);
}

template <typename... Ts, typename... Fs>
auto fold(const variant<Ts...> &value, Fs &&...fs)
{
    static_assert(sizeof...(Ts) == sizeof...(Fs),
                  "Not enough function provided to variant fold");
    return fold_at(value, value.index(),
                   forward<Fs>(fs)...);
}

string render_json_value(const JSON_value &value);

string render_bool(bool b) { return b ? "true" : "false"; }

string render_double(double d) { return to_string(d); }

string render_string(const string &str)
{
    stringstream ss;
    ss << quoted(str);
    return ss.str();
}

string render_null(nullptr_t) { return "null"; }

string render_array(const JSON_array &arr)
{
    return string{"["} +
           join(arr.cbegin(), arr.cend(), string{", "},
                [](const JSON_value &value)
                {
                    return render_json_value(value);
                }) +
           "]";
}

string render_object(const JSON_object &obj)
{
    return string{"{"} +
           join(obj.cbegin(), obj.cend(), string{", "},
                [](const JSON_object::value_type &value)
                {
                    return render_string(value.first) + ":" +
                           render_json_value(value.second);
                }) +
           "}";
}

string render_json_value(const JSON_value &value)
{
    return fold(value,
                render_bool, render_double, render_string,
                render_null, render_array, render_object);
}

int main()
{
    JSON_array arr{JSON_wrapper{false}, JSON_wrapper{0.21}, JSON_wrapper{"hi"}};

    cout << render_array(arr);
}
