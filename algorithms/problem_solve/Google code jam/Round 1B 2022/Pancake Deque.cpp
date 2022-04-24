#include <iostream>
#include <deque>

using namespace std;

int calculate(deque<int>& dq, int result) {
	int last{ 0 };

	auto pop = [&](bool pop_front) {
		if (pop_front)
		{
			if (dq.front() >= last)
				result++;
			last = max(last, dq.front());
			dq.pop_front();
		}
		else {
			if (dq.back() >= last)
				result++;
			last = max(last, dq.back());
			dq.pop_back();
		}
	};

	while (!dq.empty())
	{
		if (dq.size() == 1)
		{
			pop(true);
			break;
		}
		if (dq.front() < dq.back())
			pop(true);
		else //if (dq.front() > dq.back())
			pop(false);
		//else if (dq.front() == dq.back())
		//{
		//	dq.pop_front(); dq.pop_back();
		//	result = calculate(dq,result+2);
		//}
	}

	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i{ 0 }; i < t; i++) {
		int n;
		cin >> n;

		deque<int> dq(n);
		for (auto& elem : dq)
			cin >> elem;

		cout << "Case #" << i + 1 << ": " << calculate(dq, 0) << '\n';
	}
}