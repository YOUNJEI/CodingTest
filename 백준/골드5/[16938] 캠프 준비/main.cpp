#include <iostream>
#include <algorithm>
using namespace std;

#define BUFFER_SIZE 15
#define INF 1000000000
int g_arr[BUFFER_SIZE];
int N, L, R, X;

int dfs(int cur, int score, int minScore, int maxScore) {
	static int answer = 0;

	if (cur == N) {
		if (score >= L && score <= R && maxScore - minScore >= X)
			answer++;
		return answer;
	}
	if (g_arr[cur] + score <= R) {
		dfs(cur + 1, g_arr[cur] + score, min(minScore, g_arr[cur]), max(maxScore, g_arr[cur]));
	}
	dfs(cur + 1, score, minScore, maxScore);
	return answer;
}

int solve(void) {
	return dfs(0, 0, INF, 0);
}

int main(void) {
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) {
		cin >> g_arr[i];
	}
	cout << solve();
	return 0;
}
