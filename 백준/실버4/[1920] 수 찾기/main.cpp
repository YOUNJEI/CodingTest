#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> g_arr;
vector<int> g_query;
int N, M;

bool contain(int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (g_arr[mid] == target)
			return true;
		else if (g_arr[mid] > target)
			end = mid - 1;
		else if (g_arr[mid] < target)
			start = mid + 1;
	}
	return false;
}

vector<bool> solve(void) {
	vector<bool> answer;

	sort(g_arr.begin(), g_arr.end());
	for (int i = 0; i < M; i++) {
		if (contain(0, N - 1, g_query[i])) {
			answer.push_back(true);
		}
		else {
			answer.push_back(false);
		}
	}
	return answer;
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		g_arr.push_back(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		g_query.push_back(temp);
	}
	vector<bool> answer = solve();
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}
