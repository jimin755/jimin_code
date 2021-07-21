#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int r = 0, c = 0;

int findStr(string str, char ch) {
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == ch) {
			return i;
		}
	}
	return -1;
}

void findWater(queue<pair<pair<int, int>, int>>&que, string str, int y) {
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == '*') {
			que.push(make_pair(make_pair(y, i), 0));
		}
	}
}

void waterMove(vector<string> &map, queue<pair<pair<int, int>, int>>&water, int time) {
	pair<int, int> s;
	while (!water.empty() && water.front().second == time) {
		s.first = water.front().first.first;
		s.second = water.front().first.second;
		water.pop();
		//------ for문에 비해 비교횟수 8번가랑 적음
		if (s.first - 1 >= 0 && (map.at(s.first - 1).at(s.second) == '.'|| map.at(s.first - 1).at(s.second) == '1')) {
			water.push(make_pair(make_pair(s.first - 1, s.second), time + 1));
			map.at(s.first - 1).at(s.second) = '*';
		} // 위 
		if (s.first + 1 < r && (map.at(s.first + 1).at(s.second) == '.'|| map.at(s.first + 1).at(s.second) == '1')) {
			water.push(make_pair(make_pair(s.first + 1, s.second), time + 1));
			map.at(s.first + 1).at(s.second) = '*';
		} //아래
		if (s.second - 1 >= 0 && (map.at(s.first).at(s.second - 1) == '.'|| map.at(s.first).at(s.second - 1) == '1')) {
			water.push(make_pair(make_pair(s.first, s.second - 1),time + 1));
			map.at(s.first).at(s.second - 1) = '*';
		} //왼
		if (s.second + 1 < c && (map.at(s.first).at(s.second + 1) == '.'|| map.at(s.first).at(s.second + 1) == '1')) {
			water.push(make_pair(make_pair(s.first, s.second + 1), time + 1));
			map.at(s.first).at(s.second + 1) = '*';
		} //오
	}
}

int main(void) {
	cin >> r >> c;
	pair<int, int> s(-1, -1);
	vector<string> map;
	queue<pair<pair<int, int>, int>> que , water;
	int time=0;
	for (int i = 0; i < r; i++) {
		string tempStr = "";
		cin >> tempStr;
		map.push_back(tempStr);
		if (s.first == -1) {
			int ind = findStr(tempStr, 'S');
			if (ind != -1) {
				s.first = i;
				s.second = ind;
			}
		}
		findWater(water, tempStr, i);
	}

	bool ch = false;
	que.push(make_pair(s, time));
	while (!que.empty()) {
		s.first = que.front().first.first; // y
		s.second = que.front().first.second; // x
		map.at(s.first).at(s.second) = 'S';
		time = que.front().second;
		que.pop();
		waterMove(map, water, time);
		if (s.first - 1 >= 0) {
			if (map.at(s.first - 1).at(s.second) == '.') {
				que.push(make_pair(make_pair(s.first - 1, s.second), time + 1));
				map.at(s.first - 1).at(s.second) = '1';
			}
			else if (map.at(s.first - 1).at(s.second) == 'D') {
				time++;
				ch = true;
				break;
			}
		} // 위 
		if (s.first + 1 < r) {
			if (map.at(s.first + 1).at(s.second) == '.') {
				que.push(make_pair(make_pair(s.first + 1, s.second), time + 1));
				map.at(s.first + 1).at(s.second) = '1';
			}
			else if (map.at(s.first + 1).at(s.second) == 'D') {
				time++;
				ch = true;
				break;
			}
		} //아래
		if (s.second - 1 >= 0 ) {
			if (map.at(s.first).at(s.second - 1) == '.') {
				que.push(make_pair(make_pair(s.first, s.second - 1), time + 1));
				map.at(s.first).at(s.second - 1) = '1';
			}
			else if (map.at(s.first).at(s.second - 1) == 'D') {
				time++;
				ch = true;
				break;
			}
		} //왼
		if (s.second + 1 < c ) {
			if (map.at(s.first).at(s.second + 1) == '.') {
				que.push(make_pair(make_pair(s.first, s.second + 1), time + 1));
				map.at(s.first).at(s.second + 1) = '1';
			}
			else if (map.at(s.first).at(s.second + 1) == 'D') {
				time++;
				ch = true;
				break;
			}
		} //오
		time++;
		map.at(s.first).at(s.second) = '1';
	}

	if (ch) {
		cout << time;
	}
	else {
		cout << "KAKTUS";
	}
	return 0;
}