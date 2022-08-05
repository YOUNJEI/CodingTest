#include <iostream>
#include <vector>
using namespace std;

#define MAXLEN 1000000000
vector<int> g_tree;
int N, M;

int calc(int mid) {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		if (g_tree[i] > mid)
			sum += g_tree[i] - mid;
	}
	return sum;
}

int binarySearch(int start, int end) {
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;
		
		int getTree = calc(mid);
		if (getTree > M) {
			start = mid + 1;
		}
		else if (getTree < M) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return end;
}

int solve(void) {
	int answer;

	answer = binarySearch(0, MAXLEN);
	return answer;
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int temp;

		cin >> temp;
		g_tree.push_back(temp);
	}
	cout << solve();
	return 0;
}
