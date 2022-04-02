#include <iostream>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

auto get_input() {
	int K{}, N{}, F{};
	cin >> K >> N >> F;

	// vector<pair<number of friend, list of friend>>
	vector<pair<int, vector<bool>>> friends_list(N, { 0, vector<bool>(N, false) });

	for (int i{ 0 }; i < F; i++) {
		int x, y;
		cin >> x >> y;
		friends_list[x - 1].second[y - 1] = true;
		friends_list[y - 1].second[x - 1] = true;

		++friends_list[x - 1].first;
		++friends_list[y - 1].first;
	}

	return make_tuple(K, N, F, friends_list);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// variables
	auto [K, N, F, friends_list] {get_input()};
	vector<bool> result(900, false);
	bool has_result{ false };

	// helper functions
	auto print = [&]() {
		for (int i{ 0 }; i < N; i++)
			if (result[i])
				cout << i + 1 << "\n";

	};

	auto not_selected = [&](int y)
	{
		for (int x{ 0 }; x < N; x++)
			if (result[x])
				if (!friends_list[y].second[x])
					return false;

		return true;
	};

	// search function
	function<void(int, int)> dfs = [&](int y, int x)
	{
		if (has_result)
			return;

		if (x == K) {
			print();
			has_result = true;
			return;
		}

		for (int i{ y }; i < N; i++) {
			if (!friends_list[y].second[i])
				continue;
			if (!not_selected(i))
				continue;

			result[i] = true;
			dfs(i, x + 1);
			result[i] = false;
		}
	};

	// find result
	for (int y{ 0 }; y < N - K + 1; y++) {

		if (friends_list[y].first < K - 1)
			continue;
		if (has_result)
			break;

		result[y] = true;
		dfs(y, 1);
		result[y] = false;
	}

	// out put
	if (!has_result)
		cout << -1;

	return 0;
}

