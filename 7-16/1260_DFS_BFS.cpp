#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

vector<int> BFS(int startP, vector<vector<int>> map) {
	queue<int> que;
	vector<int> order;
	vector<int> route(map.size(), -1);
	que.push(startP-1);
	while (!que.empty()) {
		int point = que.front();
		if (route.at(point) == -1) {
			order.push_back(point);
		}
		route.at(point) = 1;
		que.pop();
		for (int x = 0; x < map.size(); x++) {
			if (map.at(point).at(x) == 1 && route.at(x)!=1) {
				que.push(x);
			}
		}
	}
	return order;
}

vector<int> DFS(int startP, vector<vector<int>> map) {
	stack<int> st;
	vector<int> order;
	vector<int> route(map.size(), -1);
	st.push(startP - 1);
	while (!st.empty()) {
		int point = st.top();
		if (route.at(point) == -1) {
			order.push_back(point);
		}
		route.at(point) = 1;
		st.pop();
		for (int x = map.size()-1; x >=0 ; x--) {
			if (map.at(point).at(x) == 1 && route.at(x) == -1) {
				st.push(x);
			}
		}
	}
	return order;
}

int main(void) {
	int n = 0, m = 0, startPoint = 0;
	cin >> n >> m >> startPoint;
	vector<vector<int>> map(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		map.at(a - 1).at(b - 1) = 1;
		map.at(b - 1).at(a - 1) = 1;
	}

	vector<int> a = DFS(startPoint, map);
	vector<int> b = BFS(startPoint, map);

	for (int i = 0; i < a.size()-1; i++) {
		cout << a.at(i)+1 << " ";
	}
	cout << a.at(a.size() - 1)+1 << endl;

	for (int i = 0; i < b.size() - 1; i++) {
		cout << b.at(i)+1 << " ";
	}
	cout << b.at(b.size() - 1)+1 << endl;

	return 0;
}