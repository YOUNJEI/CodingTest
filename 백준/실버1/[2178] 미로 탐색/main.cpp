#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define BUFFER_SIZE 100
string g_arr[BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
int N, M;

int bfs(void)
{
	static int dx[] = {1, -1, 0, 0};
	static int dy[] = {0, 0, 1, -1};
	queue<tuple<int, int, int>> q;	// r, c, d
	g_visit[0][0] = true;
	q.push(make_tuple(0, 0, 0));

	while (!q.empty())
	{
		int r = get<0>(q.front());
		int c = get<1>(q.front());
		int d = get<2>(q.front());
		q.pop();

		if (r == N - 1 && c == M - 1)
			return (d + 1);
		for (int dir = 0; dir < 4; dir++)
		{
			int nr = r + dx[dir];
			int nc = c + dy[dir];

			if (nr >= 0 && nr < N && nc >= 0 && nc < M)
			{
				if (g_arr[nr][nc] == '1' && !g_visit[nr][nc])
				{
					g_visit[nr][nc] = true;
					q.push(make_tuple(nr, nc, d + 1));
				}
			}
		}
	}
	return (-1);
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> g_arr[i];
	cout << bfs() << '\n';
	return (0);
}
