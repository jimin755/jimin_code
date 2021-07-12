#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	vector<int>arr(n + 3, 0);
	vector<int>dp(n + 3, 0);
	for (int i = 3; i < n+3; i++) {
		cin >> arr.at(i);
		dp.at(i) = max(dp.at(i - 3) + arr.at(i) + arr.at(i - 1),
			dp.at(i - 2) + arr.at(i));
		dp.at(i) = max(dp.at(i), dp.at(i - 1));
	}

	cout << dp.at(n + 2);

	return 0;
}
