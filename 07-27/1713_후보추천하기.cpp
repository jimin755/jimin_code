#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>

using namespace std;

void insert(vector<pair<int, pair<int, int>>> &photoCase, int fNum) {
	bool check = true;
	int pSize = photoCase.size();
	for (int i = 0; i < pSize; i++) {
		if (photoCase.at(i).first == fNum) { // 찾는 사람일 경우 추천수 늘리기
			photoCase.at(i).second.first++;
			check = false;
		}
		photoCase.at(i).second.second++; // 시간 늘리기
	}
	if (check) { // 만약 찾는 사람이 추천 받은적이 없었다면 추가
		photoCase.push_back(make_pair(fNum, make_pair(1, 1)));
	}
}

void pop(vector<pair<int, pair<int, int>>>& photoCase) {
	pair<int, int> ch1 = make_pair(-1, 100001); // 사람 / 추천수 or 사람 / 시간
	int pSize = photoCase.size();
	int index = 0;
	vector< pair<int,pair<int, int>>> a; // 인덱스 /사람 / 시간 중복되는 사람 저장
	for (int i = 0; i < pSize - 1; i++) { 
		// 사이즈를 하나 줄인 이유는 미리 넣고 pop하는 식으로 코드를 짜서 삭제 연산에 새로 들어올 사람이 영향을 받지 않게 하기 위해서다.
		if (photoCase.at(i).second.first < ch1.second) {
			ch1.first = photoCase.at(i).first;
			ch1.second = photoCase.at(i).second.first;
			index = i;
			if (!a.empty()) {
				a.clear();
			}
			a.push_back(make_pair(i, ch1)); 
		}
		else if (photoCase.at(i).second.first == ch1.second) {
			a.push_back(make_pair(i, make_pair(photoCase.at(i).first, photoCase.at(i).second.first)));
		} // 추천수가 같은것이 있는 경우
	}
	if (a.size() > 1) {
		ch1 = make_pair(-1, -1);
		for (int i = 0; i < a.size(); i++) {
			if (a.at(i).second.second > ch1.second ) {
				ch1.first = photoCase.at(i).first;
				ch1.second = photoCase.at(i).second.second;
				index = i;
			}
		} //오래되면 지우는거
		for (int i = a.at(index).first; i < pSize - 1; i++) {
			pair<int, pair<int, int>> temp = photoCase.at(i);
			photoCase.at(i) = photoCase.at(i + 1);
			photoCase.at(i + 1) = temp;
		} // 벡터의 erase 연산은 삭제할 값 부터 끝까지 다 지우고 다시 삽입하는 구조라 erase 사용전 삭제 대상을 미리 맨 뒤로 빼고 삭제하여 연산의 오버헤드를 줄여줌
	}
	else {
		for (int i = index; i < pSize - 1; i++) {
			pair<int, pair<int, int>> temp = photoCase.at(i);
			photoCase.at(i) = photoCase.at(i + 1);
			photoCase.at(i + 1) = temp;
		}
	}
	photoCase.erase(photoCase.begin() + pSize - 1);
}

int main(void) {
	int n, stdNum;
	cin >> n >> stdNum;
	vector<pair<int, pair<int, int>>> photoCase; // 학생 번호,  추천수, case안에 있던 시간
	int Idx = 0;
	for (int i = 0; i < stdNum; i++) {
		int temp;
		cin >> temp;
		insert(photoCase, temp);
		if (photoCase.size() > n) {
			pop(photoCase);
		}
	}
	sort(photoCase.begin(), photoCase.end());
	for (int i = 0; i < photoCase.size(); i++) {
		cout << photoCase.at(i).first << " ";
	}
}