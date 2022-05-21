#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define BUFFER_SIZE 200
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
int N, M;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int sr, int sc)
{
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(sr, sc, 1));
	g_visit[sr][sc] = true;
	
	while (!q.empty())
	{
		int r = get<0>(q.front());
		int c = get<1>(q.front());
		int d = get<2>(q.front());
		q.pop();
		if (r == N - 1 && c == M - 1)
			return (d);
		for (int dir = 0; dir < 4; dir++)
		{
			int nr = r + dx[dir];
			int nc = c + dy[dir];

			if (nr >= 0 && nr < N && nc >= 0 && nc < M)
			{
				if (g_arr[nr][nc] && !g_visit[nr][nc])
				{
					q.push(make_tuple(nr, nc, d + 1));
					g_visit[nr][nc] = true;
				}
			}
		}
	}
	return (-1);
}

int main(void)
{
	cin>>N>>M;
	
	string temp;
	for (int i = 0; i < N; i++)
	{
		cin>>temp;
		for (int j = 0; j < M; j++)
		{
			g_arr[i][j] = temp[j] - '0';
		}
	}
	cout<<bfs(0, 0);
	return (0);
}
