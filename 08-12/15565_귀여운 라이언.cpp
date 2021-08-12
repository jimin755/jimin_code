#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		if (temp == 1) {
			arr.push_back(make_pair(i, temp));
		}
	}
	int minSize = n;
	if (arr.size() < k) {
		cout << -1;
	}
	else {
		for (int i = k - 1; i < arr.size(); i++) {
			int size = arr.at(i).first - arr.at(i - (k - 1)).first + 1;
			minSize = min(size, minSize);
		}
		cout << minSize;
	}
	return 0;
}