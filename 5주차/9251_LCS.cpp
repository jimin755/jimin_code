#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	string str1 = "", str2 = "";
	cin >> str1 >> str2;
	int yL = str2.length() + 1, xL = str1.length() + 1;
	vector<vector<int>>dp(yL, vector<int>(xL, 0));

	for (int y = 1; y < yL; y++) {
		for (int x = 1; x < xL; x++) {
			if (str2.at(y - 1) == str1.at(x - 1)) {
				dp.at(y).at(x) = dp.at(y - 1).at(x - 1) + 1;
			}
			else {
				dp.at(y).at(x) = max(dp.at(y).at(x - 1), dp.at(y - 1).at(x));
			}
		}
	}
	cout << dp.at(yL - 1).at(xL - 1);
	return 0;
}