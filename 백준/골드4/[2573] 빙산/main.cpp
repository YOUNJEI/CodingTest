#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define BUFFER_SIZE 300
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
int g_decrease[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
int N, M;

int max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

void decrease(queue<tuple<int, int, int>> &q, int d)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (g_arr[i][j])
			{
				g_arr[i][j] = max(g_arr[i][j] - g_decrease[i][j], 0);
				g_decrease[i][j] = 0;
				if (g_arr[i][j])
					q.push(make_tuple(i, j, d + 1));
			}
		}
	}
}

void dfs(int r, int c)
{
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	g_visit[r][c] = true;
	for (int dir = 0; dir < 4; dir++)
	{
		int nr = r + dx[dir];
		int nc = c + dy[dir];

		if (nr >= 0 && nr < N && nc >= 0 && nc < M && g_arr[nr][nc] && !g_visit[nr][nc])
			dfs(nr, nc);
	}
}

void resetvisit(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			g_visit[i][j] = false;
		}
	}
}

bool check(void)
{
	int count = 0;

	resetvisit();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (g_arr[i][j] && !g_visit[i][j])
			{
				dfs(i, j);
				count++;
			}
		}
	}
	if (count >= 2)
		return (true);
	return (false);
}

int bfs()
{
	int r, c, d, dir;
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	queue<tuple<int, int, int>> q;

	d = -1;
	while (true)
	{
		bool flag = true;
		decrease(q, d);
		if (check())
			return (d);
		while (!q.empty())
		{
			flag = false;
			r = get<0>(q.front());
			c = get<1>(q.front());
			d = get<2>(q.front());
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nr = r + dx[i];
				int nc = c + dy[i];

				if (nr >= 0 && nr < N && nc >= 0 && nc < M && g_arr[nr][nc] == 0)
					g_decrease[r][c]++;
			}
		}
		if (flag)
			break;
	}
	return (-1);
}

void solution(void)
{
	int answer = 0;

	answer = bfs();
	cout<<answer + 1<<endl;
}

int main(void)
{
	cin>>N>>M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin>>g_arr[i][j];
		}
	}
	solution();
	return (0);
}
