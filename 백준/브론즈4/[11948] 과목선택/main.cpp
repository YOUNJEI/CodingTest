#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const int &n1, const int &n2) {
	return n1 > n2;
}

int solve(vector<int> vs, vector<int> vh) {
	int answer = 0;

	sort(vs.begin(), vs.end(), compare);
	sort(vh.begin(), vh.end(), compare);
	for (int i = 0; i < 3; i++) {
		answer += vs[i];
	}
	answer += vh[0];
	return answer;
}

int main(void) {
	vector<int> vs;	// 4 subjects of science
	vector<int> vh;	// 2 subjects of history
	
	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		vs.push_back(temp);
	}
	for (int i = 0; i < 2; i++) {
		int temp;
		cin >> temp;
		vh.push_back(temp);
	}
	cout << solve(vs, vh);
	return (0);
}
