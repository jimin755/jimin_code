#include<iostream>
#include<vector>

using namespace std;

#define INF 999999999;

int n,answer;
vector<vector<int>> map(16, vector<int>(16, 0));
vector<vector<int>> dp(16, vector<int>(1 << 16, 0));

int func(int curNode, int stat){
	if (stat == answer) {
		if (map.at(curNode).at(0) == 0) {
			return INF;
		} // 0의 값이 0이면 순회할 길이 없는 것
		else {
			return map.at(curNode).at(0);
		} // 길이 있을때 값 반환
	} //답에 도달 했을 떄

	if (dp.at(curNode).at(stat) != 0) {
		return dp.at(curNode).at(stat);
	} //dp값이 있을 때
	
	int minV = INF;
	for (int i = 0; i < n; i++) {
		if (((stat & (1 << i)) == 0) && (map[curNode][i] != 0)) {
			minV = min(minV, func(i, (stat | (1 << i))) + map[curNode][i]);
		}
	}
	dp.at(curNode).at(stat) = minV;
	return minV;
}

int main(void) {
	cin >> n;
	answer = (1 << n) - 1;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map.at(y).at(x);
		}
	}
	cout << func(0, 1);
	return 0;
}