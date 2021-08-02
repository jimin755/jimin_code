#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(void) {
	int n, m;
	cin >> n >> m;
	vector<bool>a(n + 1, false);
	vector<int> indegree(n + 1, 0);
	vector<int> list;
	vector<vector<int>> tre(n + 1, vector<int>(0, 0));
	for (int i = 0; i < m; i++) {
		int small, big;
		cin >> small >> big;
		a.at(small) = true;
		a.at(big) = true;
		tre.at(small).push_back(big);
		indegree.at(big)++;
	}
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (indegree.at(i) == 0) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		int small = que.front();
		list.push_back(small);
		que.pop();
		for (int i = 0; i < tre.at(small).size(); i++) {
			int temp = tre.at(small).at(i);
			if (--indegree.at(temp) == 0) {
				que.push(temp);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a.at(i) == false) {
			list.push_back(i);
		}
	}
	cout << list.at(0);
	for (int i = 1; i < n; i++) {
		cout << " " << list.at(i);
	}
	return 0;
}