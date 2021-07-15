#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int BFS(int startX,int startY,int areaNum,vector<vector<int>> map, vector<vector<int>> &area) {
	queue<pair<int,int>> que;
	int houseNum = 0;
	que.push(make_pair(startX, startY));
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		if (area.at(y).at(x) != -1) {
			que.pop();
			continue;
		}
		houseNum++;
		area.at(y).at(x) = areaNum;

		int upX = x, upY = y - 1;
		int downX = x, downY = y + 1;
		int leftX = x - 1, leftY = y;
		int rightX = x + 1, rightY = y;
		if (upY >= 0 && area.at(upY).at(upX)==-1 && map.at(upY).at(upX) == 1) {
			que.push(make_pair(upX, upY));
		}
		if (downY < map.size() && area.at(downY).at(downX) == -1 && map.at(downY).at(downX) == 1) {
			que.push(make_pair(downX, downY));
		}
		if (leftX >= 0 && area.at(leftY).at(leftX) == -1 && map.at(leftY).at(leftX) == 1) {
			que.push(make_pair(leftX, leftY));
		}
		if (rightX < map.size() && area.at(rightY).at(rightX) == -1 && map.at(rightY).at(rightX) == 1) {
			que.push(make_pair(rightX, rightY));
		}
	}
	return houseNum;
}

int main(void) {
	int n = 0, areaNum = 1;
	cin >> n;

	vector<vector<int>> map(n, vector<int>(n, 0));
	vector<vector<int>> area(n, vector<int>(n, -1));
	vector<int> houseNum;

	for (int y = 0; y < n; y++) {
		string a;
		cin >> a;
		for (int x = 0; x < n; x++) {
			map.at(y).at(x) = a.at(x) - '0';
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map.at(y).at(x) == 1 && area.at(y).at(x) == -1) {
				houseNum.push_back(BFS(x, y, areaNum, map, area));
				areaNum++;
			}
		}
	}
	if (areaNum != 0) {
		cout << areaNum - 1 << endl;
		sort(houseNum.begin(), houseNum.end());
		for (int i = 0; i < areaNum - 1; i++) {
			cout << houseNum.at(i) << endl;
		}
	}
	else {
		cout << 0 << endl;
	}


	return 0;
}