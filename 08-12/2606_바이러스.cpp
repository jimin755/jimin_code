#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(void) {
	int n,link;
	cin >> n >> link;
	vector<vector<int>> map(n + 1, vector<int>(0, 0));
	for (int i = 0; i < link; i++) {
		int a, b;
		cin >> a >> b;
		map.at(a).push_back(b);
		map.at(b).push_back(a);
	}
	
	stack<int> stk;
	vector<bool>visit(n + 1, true);
	visit.at(1) = false;
	for (int i = 0; i < map.at(1).size(); i++) {
		stk.push(map.at(1).at(i));
		visit.at(map.at(1).at(i)) = false;
	}
	int comNum = 0;

	while (!stk.empty()) {
		int node = stk.top();		
		stk.pop();
		comNum++;
		for (int i = 0; i < map.at(node).size(); i++) {
			int ind = map.at(node).at(i);
			if (visit.at(ind)) {
				stk.push(ind);
				visit.at(ind) = false;
			}
		}
	}
	cout << comNum;
	return 0;
}