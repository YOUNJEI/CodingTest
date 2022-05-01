#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define BUFFER_SIZE 100
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];

int N, M;

int bfs()
{
	int answer = 0;
	int height = 500;
	int i, j, r, c, h, dir;
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0 , -1};
	queue <tuple<int, int, int>> q;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < M)
		{
			while (height >= 1)
			{
				if (g_arr[i][j] && g_arr[i][j] == height && g_visit[i][j] == false)
				{
					q.push(make_tuple(i, j, height));
					g_visit[i][j] = true;
					answer++;
					while (!q.empty())
					{
						r = get<0>(q.front());
						c = get<1>(q.front());
						h = get<2>(q.front());
						q.pop();

						dir = -1;
						while (dir < 4)
						{
							dir++;
							int nr = r + dx[dir];
							int nc = c + dy[dir];

							if (nr < 0 || nr > N - 1 || nc < 0 || nc > M -1)
								continue ;
							if (g_arr[nr][nc] && g_arr[nr][nc] <= h && g_visit[nr][nc] == false)
							{
								q.push(make_tuple(nr, nc, height));
								g_visit[nr][nc] = true;
							}
						}
					}
				}
				height--;
			}
			j++;
		}
		i++;
	}
	return (answer);
}

void solution(void)
{
	int answer = 0;

	answer = bfs();
	cout<<answer<<endl;
}

int main(void)
{
	int i, j;

	cin>>N>>M;
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
}
