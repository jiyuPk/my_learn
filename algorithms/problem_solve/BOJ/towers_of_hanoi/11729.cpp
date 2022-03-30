#include <iostream>
#include <functional>
#include <deque>

using namespace std;

enum Tower { A, B, C };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// variables
	int number_of_disks{};
	cin >> number_of_disks;
	deque<int> tower_of_hanoi;
	for (int i{ 0 }; i < number_of_disks; i++) {
		tower_of_hanoi.push_front(i);
	}

	// helper funtions
	auto move_disks = [](Tower from, Tower to) {
		cout << from + 1 << " " << to + 1 << "\n";
	};

	// calculate function
	function<void(deque<int>&, Tower, Tower, Tower)> calculate = [&](deque<int>& tower, Tower from, Tower use, Tower to) {
		if (tower.size() == 1) {
			move_disks(from, to);
		}
		else if (tower.size() > 1)
		{
			int disc = tower.back();
			tower.pop_back();

			// step 1
			deque<int> save = tower;
			calculate(tower, from, to, use);

			// step 2
			move_disks(from, to);

			// step 3
			if (save.size() > 0) {
				calculate(save, use, from, to);
			}
		}
	};

	// out put
	cout << (1 << number_of_disks) - 1 << "\n";
	calculate(tower_of_hanoi, A, B, C);
}