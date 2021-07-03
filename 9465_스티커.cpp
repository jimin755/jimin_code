#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//300ms

int main(void) {
	int t = 0;
	cin >> t;

	vector<int> maxV;

	for (int z = 0; z < t; z++) {

		int n = 0;
		cin >> n;
		vector<vector<int>> arr(2, vector<int>(n, 0));
		vector<vector<int>> dp(2, vector<int>(n + 1, 0));
		
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < n; x++) {
				cin >> arr.at(y).at(x);
			}
		}

		dp.at(0).at(1) = arr.at(0).at(0);
		dp.at(1).at(1) = arr.at(1).at(0);

		for (int x = 2; x <= n; x++) {
			dp.at(0).at(x) = max(dp.at(1).at(x - 1), dp.at(1).at(x - 2)) + arr.at(0).at(x - 1);
			dp.at(1).at(x) = max(dp.at(0).at(x - 1), dp.at(0).at(x - 2)) + arr.at(1).at(x - 1);
		}
		maxV.push_back(max(dp.at(0).at(n), dp.at(1).at(n)));

	}

	for (int i = 0; i < t; i++) {
		cout << maxV.at(i) << endl;
	}

	return 0;
}




/* 4268kb, 308ms 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int actionFunc() {
	int n = 0;
	cin >> n;
	vector<vector<int>> arr(2, vector<int>(n, 0));
	vector<vector<int>> dp(2, vector<int>(n+1, 0));
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < n; x++) {
			cin >> arr.at(y).at(x);
		}
	}
	dp.at(0).at(1) = arr.at(0).at(0);
	dp.at(1).at(1) = arr.at(1).at(0);
	for (int x = 2; x <= n; x++) {
		dp.at(0).at(x) = max(dp.at(1).at(x - 1), dp.at(1).at(x - 2)) + arr.at(0).at(x - 1);
		dp.at(1).at(x) = max(dp.at(0).at(x - 1), dp.at(0).at(x - 2)) + arr.at(1).at(x - 1);
	}

	return max(dp.at(0).at(n), dp.at(1).at(n));
}

int main(void) {
	int t = 0;
	cin >> t;

	vector<int> arr;
	for (int y = 0; y < t; y++) {
		arr.push_back(actionFunc());
	}

	for (int y = 0; y < t; y++) {
		cout << arr.at(y) << endl;;
	}

	return 0;
}
*/