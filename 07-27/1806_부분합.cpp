#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


// 투 포인터
int main(void) {
	int n = 0, s = 0, len = 0;
	cin >> n >> s;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr.at(i);
		if (arr.at(i) >= s) {
			len = 1;
			cout << len;
			return 0;
		}
	}
	int left = 0, right = 0, sum = 0, minLen = 100001;
	while (left < n) {
		if (left < n && right < n) {
			if (sum >= s) {
				sum -= arr.at(left++);
				minLen = min(len, minLen);
				len--;
			}
			else if (sum < s) {
				sum += arr.at(right++);
				len++;
			}
		}
		else {
			if (sum >= s) {
				sum -= arr.at(left++);
				minLen = min(len, minLen);
				len--;
			}
			else {
				break;
			}
		}
	}
	if (minLen == 100001) {
		cout << 0;
	}
	else {
		cout << minLen;
	}


	return 0;
}