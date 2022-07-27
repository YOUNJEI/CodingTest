#include <iostream>
#include <cstdlib>
using namespace std;

#define BUFFER_SIZE 14

int g_arr[BUFFER_SIZE];
int N;

bool checkRule(int cur) {
	for (int i = 0; i < cur; i++) {
		if (g_arr[i] == g_arr[cur])
			return false;

		int xDiff = abs(g_arr[cur] - g_arr[i]);
		int yDiff = abs(cur - i);
		if (xDiff == yDiff)
			return false;
	}
	return true;
}

int dfs(int cur) {
	static int answer = 0;
	if (cur == N) {
		answer++;
		return answer;
	}
	for (int i = 0; i < N; i++) {
		g_arr[cur] = i;
		if (checkRule(cur)) {
			dfs(cur + 1);
		}
	}
	return answer;
}

int solve() {
	return dfs(0);
}

int main(void) {
	cin >> N;

	cout << solve();
	return 0;
}
