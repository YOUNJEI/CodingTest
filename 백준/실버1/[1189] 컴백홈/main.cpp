#include <iostream>
using namespace std;
#define BUFFER_SIZE 5

string g_arr[BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
int R, C, K;

int dfs(int r, int c, int move) {
	static int answer = 0;
	static int dx[] = {1, -1, 0, 0};
	static int dy[] = {0, 0, 1, -1};

	if (r == 0 && c == C - 1) {
		if (move == K)
			answer++;
		return answer;
	}
	g_visit[r][c] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nr = r + dx[dir];
		int nc = c + dy[dir];

		if (nr >= 0 && nr < R && nc >= 0 && nc < C && !g_visit[nr][nc] && g_arr[nr][nc] != 'T')
		{
			dfs(nr, nc, move + 1);
		}
	}
	g_visit[r][c] = false;
	return answer;
}

int solve() {
	return dfs(R - 1, 0, 1);
}

int main(void) {
	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		cin >> g_arr[i];
	}
	cout << solve();
	return 0;
}
