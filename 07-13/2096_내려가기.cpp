#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	vector<vector<pair<int, int>>> dp(2, vector<pair<int, int>>(3, make_pair(0, 0)));

	int a = 0, b = 0, c = 0;
	cin >> dp.at(0).at(0).first >> dp.at(0).at(1).first >> dp.at(0).at(2).first;
	dp.at(0).at(0).second = dp.at(0).at(0).first;
	dp.at(0).at(1).second = dp.at(0).at(1).first;
	dp.at(0).at(2).second = dp.at(0).at(2).first;

	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		dp.at(1).at(0).first = max(dp.at(0).at(0).first, dp.at(0).at(1).first) + a;
		dp.at(1).at(1).first = max(max(dp.at(0).at(0).first, dp.at(0).at(1).first), dp.at(0).at(2).first) + b;
		dp.at(1).at(2).first = max(dp.at(0).at(2).first, dp.at(0).at(1).first) + c;

		dp.at(1).at(0).second = min(dp.at(0).at(0).second, dp.at(0).at(1).second) + a;
		dp.at(1).at(1).second = min(min(dp.at(0).at(0).second, dp.at(0).at(1).second), dp.at(0).at(2).second) + b;
		dp.at(1).at(2).second = min(dp.at(0).at(2).second, dp.at(0).at(1).second) + c;

		dp.at(0).at(0).first = dp.at(1).at(0).first;
		dp.at(0).at(1).first = dp.at(1).at(1).first;
		dp.at(0).at(2).first = dp.at(1).at(2).first;

		dp.at(0).at(0).second = dp.at(1).at(0).second;
		dp.at(0).at(1).second = dp.at(1).at(1).second;
		dp.at(0).at(2).second = dp.at(1).at(2).second;
	}

	cout << max(max(dp.at(0).at(0).first, dp.at(0).at(1).first), dp.at(0).at(2).first);
	cout << " " << min(min(dp.at(0).at(0).second, dp.at(0).at(1).second), dp.at(0).at(2).second);
	return 0;
}


/*
#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	vector<vector<int>> dp(n, vector<int>(3, 0));
	vector<vector<int>> minDp(n, vector<int>(3, 0));
	cin >> dp.at(0).at(0) >> dp.at(0).at(1) >> dp.at(0).at(2);

	minDp.at(0).at(0) = dp.at(0).at(0);
	minDp.at(0).at(1) = dp.at(0).at(1);
	minDp.at(0).at(2) = dp.at(0).at(2);

	int a = 0, b = 0, c = 0;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		dp.at(i).at(0) = max(dp.at(i - 1).at(0), dp.at(i - 1).at(1)) + a;
		dp.at(i).at(1) = max(max(dp.at(i - 1).at(0), dp.at(i - 1).at(1)), dp.at(i - 1).at(2)) + b;
		dp.at(i).at(2) = max(dp.at(i - 1).at(2), dp.at(i - 1).at(1)) + c;

		minDp.at(i).at(0) = min(minDp.at(i - 1).at(0), minDp.at(i - 1).at(1)) + a;
		minDp.at(i).at(1) = min(min(minDp.at(i - 1).at(0), minDp.at(i - 1).at(1)), minDp.at(i - 1).at(2)) + b;
		minDp.at(i).at(2) = min(minDp.at(i - 1).at(2), minDp.at(i - 1).at(1)) + c;
	}

	cout << max(max(dp.at(n - 1).at(0), dp.at(n - 1).at(1)), dp.at(n - 1).at(2)) <<" "<<min(min(minDp.at(n - 1).at(0), minDp.at(n - 1).at(1)), minDp.at(n - 1).at(2));
	return 0;
}
*/
