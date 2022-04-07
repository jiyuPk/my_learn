#include <iostream>
#include <vector>
#include <utility>
#include <ranges>

using namespace std;

class eval {
public:
	eval() = default;
	eval(int n)
		: criteria(n) {}

	bool operator()(const pair<string, int>& elem) {
		return elem.second > criteria;
	}
	
private:
	int criteria{ 50 };
};

int main() {
	vector<pair<string, int>> grade{
		{"Math", 90},
		{"Eng", 60},
		{"Geo", 70},
		{"Bio", 30},
		{"Phy", 100},
		{"Che", 50}
	};

	auto to_string = [](const pair<string, int>& elem) {
		return elem.first;
	};

	// eval with default criteria 50
	eval default_eval{};
	eval eval_over_90(90);
	
	auto good_subject = grade | views::filter(eval_over_90)
							  | views::transform(to_string);

	for (auto i : good_subject) {
		cout << i << endl;
	}
	
	grade.clear();

	//// nothing will print
	try {
		for (auto i : good_subject)
			cout << i << endl;
	}
	catch (const std::exception&)
	{}

	return 0;
}
