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
            if (arr.at(i) < arr.at(j)) {
                if (min < dp.at(j)) {
                    min = dp.at(j);
                }
            }
        }
        dp.at(i) = min + 1;
        maxV = max(maxV, dp.at(i));
    }

    cout << maxV;
    return 0;
}
