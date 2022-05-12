#include <iostream>
using namespace std;

#define BUFFER_SIZE 19
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];

int dfs(int r, int c, int target, int dir, int count)
{
	int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
	int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
	int odx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
	int ody[] = {0, 0, -1, 1, 1, -1, 1, -1};
	int nr, nc;
	int temp = 0;
	bool flag = false;

	g_visit[r][c] = true;
	switch (dir)
	{
		case 0:
			for (int d = 0; d < 8; d++)
			{
				nr = r + dx[d];
				nc = c + dy[d];
				
				if (nr >= 0 && nr < BUFFER_SIZE && nc >= 0 && nc < BUFFER_SIZE && g_arr[nr][nc] == target && !g_visit[nr][nc])
				{
					temp = dfs(nr, nc, target, d + 1, count + 1);
					if (temp == 5)
					{
						nr = r + odx[d];
						nc = c + ody[d];
						if (nr >= 0 && nr < BUFFER_SIZE && nc >= 0 && nc < BUFFER_SIZE && g_arr[nr][nc] == target)
							return (6);
						return (5);
					}
				}
			}
			break;
		default :
			for (int d = 0; d < 8; d++)
			{
				nr = r + dx[d];
				nc = c + dy[d];

				if (nr >= 0 && nr < BUFFER_SIZE && nc >= 0 && nc < BUFFER_SIZE && g_arr[nr][nc] == target && !g_visit[nr][nc])
				{
					if (d == dir - 1)
					{
						temp = dfs(nr, nc, target, dir, count + 1);
					}
					else
						flag = true;
				}
			}
			if (flag)
				g_visit[r][c] = false;
			if (temp)
				return (temp);
			break;
	}
	return (count);
}

void solution(void)
{
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		for (int j = 0; j < BUFFER_SIZE; j++)
		{
			if (g_arr[j][i] && !g_visit[j][i])
			{
				if (dfs(j, i, g_arr[j][i], 0, 1) == 5)
				{
					cout<<g_arr[j][i]<<endl;
					cout<<j + 1<<" "<<i + 1;
					return ;
				}
			}
		}
	}
	cout<<"0";
}

int main(void)
{
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		for (int j = 0; j < BUFFER_SIZE; j++)
		{
			cin>>g_arr[i][j];
		}
	}
	solution();
	return (0);
}
