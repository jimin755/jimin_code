#include<iostream>
#include<vector>

using namespace std;

int main(void) {

	int n = 0;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(0, 0));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x <= y; x++) {
			int temp;
			scanf("%d", &temp); // 16ms
			//cin >> temp; 44ms
			arr.at(y).push_back(temp);
			if (y != 0) {
				if (x == 0) {
					arr.at(y).at(x) += arr.at(y - 1).at(x);
				}
				else if (x == y) {
					arr.at(y).at(x) += arr.at(y - 1).at(x - 1);
				}
				else {
					arr.at(y).at(x) += max(arr.at(y - 1).at(x), arr.at(y - 1).at(x - 1));
				}
			}
		}
	}
	int maxN = 0;
	for (int i = 0; i < n; i++) {
		maxN = max(maxN, arr.at(n-1).at(i));
	}
	cout << maxN;

	return 0;
}
