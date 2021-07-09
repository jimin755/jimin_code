#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	vector<vector<long>> dp(n, vector<long>(10, 0));

	for (int i = 1; i <= 9; i++) {
		dp.at(0).at(i) = 1;
	}

	for (int y = 1; y < n; y++) {
		dp.at(y).at(0) = dp.at(y - 1).at(1);
		dp.at(y).at(9) = dp.at(y - 1).at(8);
		for (int x = 1; x < 9; x++) {
			dp.at(y).at(x) = dp.at(y - 1).at(x - 1) + dp.at(y - 1).at(x + 1) % 1000000000;
		}
	}

	long maxV = 0;
	for (int i = 0; i <= 9; i++) {
		maxV += dp.at(n - 1).at(i);
	}
	cout << maxV % 1000000000;

	return 0;
}