#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(void) {
	string str;
	queue<int> que;
	int bSize = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == 'b') {
			bSize++;
		}
	}
	int minBSize = str.length();
	int bCnt = 0;
	int aSize = str.length() - bSize;
	for (int start = 0; start < str.length(); start++) {
		int ind = start, cnt = 0;
		bCnt = 0;
		while (cnt < aSize) {
			cnt++;
			if (ind >= str.size()) {
				ind -= str.size();
			}
			if (str.at(ind) == 'b') {
				bCnt++;
			}
			ind++;
		}
		minBSize = min(minBSize, bCnt);
	}
	cout << minBSize;
	return 0;
}