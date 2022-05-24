#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define BUFFER_SIZE 50

string g_arr[BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
int N, M;

int max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

void resetVisit(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			g_visit[i][j] = false;
		}
	}
}

int bfs(int i, int j)
{
	int r, c, d;
	queue<tuple<int, int, int>> q;
	static int dx[] = {1, -1, 0, 0};
	static int dy[] = {0, 0, 1, -1};

	q.push(make_tuple(i, j, 0));
	g_visit[i][j] = true;
	
	while(!q.empty())
	{
		r = get<0>(q.front());
		c = get<1>(q.front());
		d = get<2>(q.front());
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = r + dx[dir];
			int nc = c + dy[dir];
			
			if (nr >= 0 && nr < N && nc >= 0 && nc < M)
			{
				if (g_arr[nr][nc] == 'L' && !g_visit[nr][nc])
				{
					q.push(make_tuple(nr, nc, d + 1));
					g_visit[nr][nc] = true;
				}
			}
		}
	}
	return (d);
}

void solution(void)
{
	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (g_arr[i][j] == 'L')
			{
				resetVisit();
				answer = max(answer, bfs(i ,j));
			}
		}
	}
	cout<<answer<<'\n';
}

int main(void)
{
	cin>>N>>M;

	for (int i = 0; i < N; i++)
	{
		cin>>g_arr[i];
	}
	solution();
	return (0);
}
