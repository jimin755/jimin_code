#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main(void) {
	int n, m = 0;
	cin >> n >> m;
	vector<int> treeLen(n, 0);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &treeLen.at(i));
	}

	sort(treeLen.begin(), treeLen.end());
	int left = 0, right = 0;
	long sum = 0, pivot = 0, result = 0;
	right = treeLen.at(n - 1);

	while (left <= right) {
		pivot = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (treeLen.at(i) - pivot > 0) {
				sum += treeLen.at(i) - pivot;
			}
		}
		if (sum >= m) {
			result = pivot;
			if (sum == m) {
				break;
			}
			left = pivot + 1;
		}
		else if (sum < m) {
			right = pivot - 1;
		}
	}
	std::cout << result;
	return 0;
}