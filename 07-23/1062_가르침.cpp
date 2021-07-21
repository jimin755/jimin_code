#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/*
	a,t,c,n,i는 최소한 배워야함
*/

char arr[5] = { 'a','c','t','n','i' };
int able = 0;

string subStrTemp(string s) {
	string tStr = "";
	for (int i = 0; i < s.length(); i++) {
		for (int t = 0; t < 5; t++) {
			if (s.at(i) != arr[t]) {
				tStr += s.at(i);
			}
		}
	} // a,t,c,n,i 제거
	tStr.erase(unique(tStr.begin(), tStr.end()), tStr.end()); // 중복문자 제거
	if (tStr.length() == 0) {
		able++;
		return "";
	}
	else {
		return tStr;
	}
}

int main(void) {
	int k = 0, n = 0;
	cin >> n >> k;
	
	if (k < 5) {
		std::cout << 0;
		return 0;
	}
	else if(k==26) {
		std::cout << n;
		return 0;
	}
	else {
		k -= 5;

		vector<string> strArr;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			s = subStrTemp(s.substr(4, s.length() - 8));
			if (s != "") {
				strArr.push_back(s);
			}
		}

		// 0과1을 저장 할 벡터 생성
		vector<int> ind;

		// k개의 1 추가
		for (int i = 0; i < k; i++) {
			ind.push_back(1);
		}

		for (int i = 0; i < 26 - k; i++) {
			ind.push_back(0);
		}

		// 정렬
		sort(ind.begin(), ind.end());


		int maxCnt = 0, cnt = 0;
		bool read;
		//순열
		do {
			cnt = 0;
			vector<bool> alphabet(26, false);

		
			alphabet.at(0) = true;
			alphabet.at(2) = true;
			alphabet.at('t' - 'a') = true;
			alphabet.at('n' - 'a') = true;
			alphabet.at('i' - 'a') = true;
			

			if (ind.at(0) == 1 || ind.at(2) == 1 || ind.at('i' - 'a') == 1 || ind.at('t' - 'a') == 1 || ind.at('n' - 'a') == 1) {
				continue;
			}

			for (int i = 0; i < ind.size(); i++) {
				if (ind[i] == 1) {
					alphabet.at(i) = true;
				}
			}

			for (int i = 0; i < strArr.size(); i++){
				read = true;
				string str = strArr.at(i);
				for (int j = 0; j < str.length(); j++){
					if (alphabet.at(str.at(j) - 'a') == false){
						read = false;
						break;
					}
				}

				if (read == true){
					cnt++;
				}
			}
			maxCnt = max(maxCnt, cnt + able);
		} while (next_permutation(ind.begin(), ind.end()));
		std::cout << maxCnt;
	}
	return 0;
}