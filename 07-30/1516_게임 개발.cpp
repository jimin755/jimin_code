#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int cost[501]; // 해당 건물을 짓는데 드는 시간
int ans[501]; // 선행적으로 지어야하는 건물을 짓는 시간을 포함한 건물을 짓는데 드는 시간
int indegree[501]; // 진입 차수
vector<int> vec[501]; // 선행 건물 리스트

void bfs() {

    queue<int> q;
    for (int n = 1; n <= N; n++) {
        if (indegree[n] == 0) {
            q.push(n);
            ans[n] = cost[n];
        } // 선행 조건이 없는 건물을 먼저 짓는다.
    }

    while (!q.empty()) {
        int nedge = q.front();
        q.pop();
        for (int m = 0; m < vec[nedge].size(); m++) {
            int e = vec[nedge][m];
            ans[e] = max(ans[e], ans[nedge] + cost[e]);
            if (--indegree[e] == 0) {
                q.push(e);
            }
        }
    }
}

int main() {

    cin >> N;
    for (int n = 1; n <= N; n++) {
        int edge; // 선행 건물을 입력받을 변수
        cin >> cost[n];
        while (cin >> edge, edge != -1) {
            vec[edge].push_back(n);
            indegree[n]++;    //진입차수
        }
    }
    bfs();
    for (int n = 1; n <= N; n++){
        cout << ans[n] << endl;
    }


    return 0;

}
