#include<iostream>
#include<vector>

using namespace std;

//메모리를 줄여보려했으나 줄여지지 않았음


int main(void) {
	int n = 0;
	cin >> n;
	vector<vector<int>> dp(n, vector<int>(3, 0));
	vector<int> arr(3,0);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> arr.at(x);
		}
		if (y == 0) {
			dp.at(0).at(0) = arr.at(0);
			dp.at(0).at(1) = arr.at(1);
			dp.at(0).at(2) = arr.at(2);
		}
		else {
			dp.at(y).at(0) = min(dp.at(y - 1).at(1), dp.at(y - 1).at(2)) + arr.at(0);
			dp.at(y).at(1) = min(dp.at(y - 1).at(0), dp.at(y - 1).at(2)) + arr.at(1);
			dp.at(y).at(2) = min(dp.at(y - 1).at(0), dp.at(y - 1).at(1)) + arr.at(2);
		}
	}

	cout << min(dp.at(n - 1).at(2), min(dp.at(n - 1).at(0), dp.at(n - 1).at(1)));

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
	vector<vector<int>> arr(n, vector<int>(3, 0));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> arr.at(y).at(x);
		}
	}

	dp.at(0).at(0) = arr.at(0).at(0);
	dp.at(0).at(1) = arr.at(0).at(1);
	dp.at(0).at(2) = arr.at(0).at(2);

	for (int y = 1; y < n; y++) {
		dp.at(y).at(0) = min(dp.at(y - 1).at(1), dp.at(y - 1).at(2)) + arr.at(y).at(0);
		dp.at(y).at(1) = min(dp.at(y - 1).at(0), dp.at(y - 1).at(2)) + arr.at(y).at(1);
		dp.at(y).at(2) = min(dp.at(y - 1).at(0), dp.at(y - 1).at(1)) + arr.at(y).at(2);
	}

	cout << min(dp.at(n - 1).at(2), min(dp.at(n - 1).at(0), dp.at(n - 1).at(1)));

	return 0;
}
*/