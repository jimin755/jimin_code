#include<iostream>
#include<vector>

using namespace std;

const int MAX = 10000000;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(n, MAX));
	for (int i = 0; i < n; i++) {
		map.at(i).at(i) = 0;
	}
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		map.at(start - 1).at(end - 1) = min(cost, map.at(start - 1).at(end - 1));
	}
	for (int node = 0; node < n; node++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				map.at(y).at(x) = min(map.at(y).at(x), map.at(y).at(node) + map.at(node).at(x));
			}
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map.at(y).at(x) == MAX) {
				map.at(y).at(x) = 0;
			}
		}
	}
	for (int y = 0; y < n; y++) {
		cout << map.at(y).at(0);
		for (int x = 1; x < n; x++) {
			cout << " " << map.at(y).at(x);
		}
		cout << endl;
	}
	return 0;
}