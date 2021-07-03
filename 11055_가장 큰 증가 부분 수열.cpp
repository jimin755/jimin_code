#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    vector<int> arr(n + 1, 0);
    int maxV = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr.at(i);
        int min = 0;
        for (int j = 0; j <= i; j++) {
            if (arr.at(i) > arr.at(j)) {
                if (min < dp.at(j)) {
                    min = dp.at(j);
                }
                // 기준이 되는 값 전의 수열에서 가장 긴 증가하는 부분 수열 길이 찾음
            }// 요소의 값이 현재 기준이 되는 값 보다 작은 지 체크
        }
        dp.at(i) = min + 1;
        maxV = max(maxV, dp.at(i));
    }

    cout << maxV;
    return 0;
}