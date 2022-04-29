#include <iostream>
#include <queue>
#include <tuple>

#define BUFFER_SIZE 1000
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
int M, N;

using namespace std;

int bfs()
{
	int days = 0;
	int i, j, dir;
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	queue<tuple<int, int, int>> q;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < M)
		{
			if (g_arr[i][j] == 1)
			{
				q.push(make_tuple(i, j, days));
				g_visit[i][j] = true;
			}
			j++;
		}
		i++;
	}
	while (!q.empty())
	{
		i = get<0>(q.front());
		j = get<1>(q.front());
		days = get<2>(q.front());
		q.pop();

		g_arr[i][j] = 1;
		dir = -1;
		while (dir < 4)
		{
			dir++;
			int nr = i + dx[dir];
			int nc = j + dy[dir];

			if (nr < 0 || nr > N - 1 || nc < 0 || nc > M - 1)
				continue;
			if (g_arr[nr][nc] == 0 && g_visit[nr][nc] == false)
			{
				q.push(make_tuple(nr, nc, days + 1));
				g_visit[nr][nc] = true;
			}
		}
	}
	return (days);
}

bool isFinish(void)
{
	int i, j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < M)
		{
			if (g_arr[i][j] == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void solution(void)
{
	int answer;

	answer = -1;
	answer = bfs();
	if (isFinish())
		cout<<answer<<endl;
	else
		cout<<"-1"<<endl;
}

int main(void)
{
	int i, j;

	cin>>M>>N;
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < M)
		{
			cin>>g_arr[i][j];
			j++;
		}
		i++;
	}
	solution();
	return (0);
}
