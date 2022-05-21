#include <iostream>
using namespace std;

#define BUFFER_SIZE 1000
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
int N, M;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int r, int c)
{
	g_visit[r][c] = true;

	for (int dir = 0; dir < 4; dir++)
	{
		int nr = r + dx[dir];
		int nc = c + dy[dir];

		if (nr >= 0 && nr < N && nc >= 0 && nc < M && !g_arr[nr][nc] && !g_visit[nr][nc])
			dfs(nr, nc);
	}
}

int main(void)
{
	cin>>N>>M;

	string temp;
	for (int i = 0 ; i < N; i++)
	{
		cin>>temp;
		for (int j = 0 ; j < M; j++)
		{
			g_arr[i][j] = temp[j] - '0';
		}
	}

	int count = 0 ;
	for (int i = 0 ; i < N; i++)
	{
		for (int j = 0 ; j < M; j++)
		{
			if (!g_arr[i][j] && !g_visit[i][j])
			{
				count++;
				dfs(i, j);
			}
		}
	}
	cout<<count<<'\n';
	return (0);
}
