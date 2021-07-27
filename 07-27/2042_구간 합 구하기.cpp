#include<iostream>
#include<vector>

using namespace std;

int n = 0, m = 0, k = 0;
vector<long long> tree;
vector<long long> arr;

long long makeTree(int start, int end, int node) {
	if (start == end) {
		tree.at(node) = arr.at(start);
		return tree.at(node);
	}
	int pivot = (start + end) / 2;
	tree.at(node) = makeTree(start, pivot, node * 2) + makeTree(pivot + 1, end, node * 2 + 1);
	return tree.at(node);
}

long long searchSum(int start, int end, int node,int schStart,int schEnd) {
	if (schStart > end || schEnd < start) {
		return 0;
	}// 범위 밖
	if (schStart <= start && end <= schEnd) {
		return tree.at(node);
	}//범위 안
	int pivot = (start + end) / 2;
	long long sum = searchSum(start, pivot, node * 2, schStart, schEnd) + searchSum(pivot + 1, end, node * 2 + 1, schStart, schEnd);
	return sum;
}

long long updateSum(int start,int end,int node,int changeIdx , long long changeNum) {
	
	if (start == end && start == changeIdx) {
		tree.at(node) = changeNum;
		return tree.at(node);
	}

	int pivot = (start + end) / 2;
	if (start != end) {
		if (changeIdx <= pivot) {
			tree.at(node) = updateSum(start, pivot, node * 2, changeIdx, changeNum) + tree.at(node * 2 + 1);
		}
		else {
			tree.at(node) = tree.at(node * 2) + updateSum(pivot + 1, end, node * 2 + 1, changeIdx, changeNum);
		}
	}
	return tree.at(node);
}

int main(void) {
	cin >> n >> m >> k;
	arr.assign(n, 0);
	tree.assign(n * 4, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr.at(i);
	}

	makeTree(0, n - 1, 1);
	vector<long long> result;
	for (int i = 0; i < (m + k); i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			updateSum(0, n - 1, 1, b - 1, c);
			arr.at(b - 1) = c;
		} // 업데이트
		else {
			result.push_back(searchSum(0, n - 1, 1, b - 1, c - 1));
		} // sum
	}
	for (int i = 0; i < k; i++) {
		cout << result.at(i) << endl;
	}
	return 0;
}