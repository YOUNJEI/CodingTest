#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;

int countByRange(const vector<int> &own, int t) {
	auto right = upper_bound(own.begin(), own.end(), t);
	auto left = lower_bound(own.begin(), own.end(), t);
	return right - left;
}

vector<int> solve(vector<int> own, vector<int> query) {
	vector<int> answer;

	sort(own.begin(), own.end());
	for (int i = 0; i < query.size(); i++) {
		int count = countByRange(own, query[i]);
		
		answer.push_back(count);
	}
	return answer;
}

int main(void) {
	vector<int> own;
	vector<int> query;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;

		cin >> temp;
		own.push_back(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp;

		cin >> temp;
		query.push_back(temp);
	}
	vector<int> answer = solve(own, query);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}
