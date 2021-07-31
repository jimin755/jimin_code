#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	vector<int>indegree(n+1, 0); // 차수
	vector<int>timeCnt(n+1, 0); //걸리는 시간
	vector<vector<int>> arr(n+1, vector<int>(0, 0)); // 자신이 선행 조건인 작업들 
	vector<int> jobs; // jobs마다 걸리는 시간
	for (int i = 0; i < n; i++) {
		int time = 0, bfjobsN = 0;
		cin >> time >> bfjobsN;
		jobs.push_back(time);
		for (int t = 0; t < bfjobsN; t++) {
			int temp = 0;
			cin >> temp;
			indegree.at(i + 1)++;
			arr.at(temp).push_back(i + 1);
		}
	}

	queue<int> que;
	for (int i = 0; i < n; i++) {
		if (indegree.at(i + 1) == 0) {
			que.push(i + 1);
			timeCnt.at(i + 1) = jobs.at(i);
		}
	}

	while (!que.empty()) {
		int ind = que.front();
		que.pop();
		for (int i = 0; i < arr.at(ind).size(); i++) {
			int nextP = arr.at(ind).at(i);
			timeCnt.at(nextP) = max(timeCnt.at(nextP), timeCnt.at(ind) + jobs.at(nextP - 1));
			if (--indegree.at(nextP) == 0) {
				que.push(nextP);
			}
		}
	}
	int time = 0;
	for (int i = 0; i < n; i++) {
		time = max(time, timeCnt.at(i + 1));
	}
	cout << time;
	return 0;
}