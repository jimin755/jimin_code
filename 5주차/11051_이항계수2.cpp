#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n = 0, k = 0;
	
	cin >> n >> k;
	vector<vector<long>>dp(n + 1, vector<long>(n + 1, 1));

	for (int y = 1; y <= k; y++) {
		for (int x = 2; x <= n; x++) {
			if (y == x) {
				continue;
			}
			dp.at(y).at(x)= (dp.at(y - 1).at(x - 1) + dp.at(y).at(x - 1)) % 10007;
		}
	}
	cout << dp.at(k).at(n);

	return 0;
}