#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 2000000000

vector<int> g_home;
int N, C;

int solve(void) {
	int answer;

	sort(g_home.begin(), g_home.end());
	//answer = binarySearch(0, INF);
	answer = *(upper_bound(g_home.begin(), g_home.end(), 5500));
	return answer;
}

int main(void) {
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int temp;

		cin >> temp;
		g_home.push_back(temp);
	}
	cout << solve();
	return 0;
}
