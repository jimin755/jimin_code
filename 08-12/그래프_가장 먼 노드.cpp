#include <string>
#include <vector>
#include<iostream>
using namespace std;

const int INF = 99999;

int SmallInd(vector<int> da, vector<bool> visit) {
    int minSize = INF;
    int minInd = 0;
    for (int i = 0; i < da.size(); i++) {
        if (minSize > da.at(i) && !visit.at(i)) {
            minSize = da.at(i);
            minInd = i;
        }
    }
    return minInd;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> da(n, INF);
    vector<vector<bool>> map(n, vector<bool>(n, false));
    vector<bool> visit(n, false);
    for (int i = 0; i < edge.size(); i++) {
        int a = edge.at(i).at(0) - 1, b = edge.at(i).at(1) - 1;
        map.at(a).at(b) = true;
        map.at(b).at(a) = true;
    }
    int node = 0;
    da.at(0) = 0;
    for (int i = 0; i < n; i++) {
        visit.at(node) = true;
        for (int a = 0; a < n; a++) {
            if (map.at(node).at(a)) {
                da.at(a) = min(da.at(a), da.at(node) + 1);
            }
        }
        node = SmallInd(da, visit);
    }
    int maxV = da.at(0);
    for (int i = 1; i < n; i++) {
        if (da.at(i) == maxV) {
            answer++;
        }
        else if(da.at(i) > maxV){
            maxV = da.at(i);
            answer = 1;
        }
    }
    return answer;
}

int main(void) {
    solution(6, {{ 3, 6 }, { 4, 3 }, { 3, 2 }, { 1, 3 }, { 1, 2 }, { 2, 4 }, { 5, 2 }});
    return 0;
}