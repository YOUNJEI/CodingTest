#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define BUFFER_SIZE 50

string g_arr[BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
int N;

void resetvisit(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			g_visit[i][j] = false;
		}
	}
}

void swap(int fr, int fc, int tr, int tc)
{
	char temp;

	temp = g_arr[fr][fc];
	g_arr[fr][fc] = g_arr[tr][tc];
	g_arr[tr][tc] = temp;
}

int dfs(int r, int c, int d, char candy, int count)
{
	static int dx[] = {-1, 1, 0, 0};
	static int dy[] = {0, 0, -1, 1};
	int temp[2];

	g_visit[r][c] = true;
	if (d == -1)
	{
		/* 세로 */
		temp[0] = 0;
		for (int dir = 0; dir < 2; dir++)
		{
			int nr = r + dx[dir];
			int nc = c + dy[dir];
			
			if (nr >= 0 && nr < N && nc >= 0 && nc < N)
			{
				if (g_arr[nr][nc] == candy && !g_visit[nr][nc])
					temp[0] += dfs(nr, nc, dir, candy, count + 1);

			}
		}
		temp[1] = 0;
		for (int dir = 2; dir < 4; dir++)
		{
			int nr = r + dx[dir];
			int nc = c + dy[dir];

			if (nr >= 0 && nr < N && nc >= 0 && nc < N)
			{
				if (g_arr[nr][nc] == candy && !g_visit[nr][nc])
					temp[1] += dfs(nr, nc, dir, candy, count + 1);
			}
		}
		if (temp[0] >= temp[1])
			return (temp[0]);
		else
			return (temp[1]);
	}
	else
	{
		switch (d)
		{
			case 0:
				if (r - 1 >= 0 && g_arr[r - 1][c] == candy && !g_visit[r - 1][c])
					return (dfs(r - 1, c, d, candy, count + 1));
				break ;

			case 1:
				if (r + 1 < N && g_arr[r + 1][c] == candy && !g_visit[r + 1][c])
					return (dfs(r + 1, c, d, candy, count + 1));
				break ;

			case 2:
				if (c - 1 >= 0 && g_arr[r][c - 1] == candy && !g_visit[r][c - 1])
					return (dfs(r, c - 1, d, candy, count + 1));
				break ;

			case 3:
				if (c + 1 < N && g_arr[r][c + 1] == candy && !g_visit[r][c + 1])
					return (dfs(r, c + 1, d, candy, count + 1));
				break ;
		}
		return (count);
	}
}

int rotate(int r, int c)
{
	static int dx[] = {1, -1, 0, 0};
	static int dy[] = {0, 0, 1, -1};
	int count = 0;

	for (int dir = 0; dir < 4; dir++)
	{
		int nr = r + dx[dir];
		int nc = c + dy[dir];

		if (nr >= 0 && nr < N && nc >= 0 && nc < N)
		{
			resetvisit();
			swap(r, c, nr, nc);
			count = max(count, dfs(r, c, -1, g_arr[r][c], 0));
			swap(r, c, nr, nc);
		}
	}
	return (count);
}

int solution(void)
{
	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer = max(answer, rotate(i, j));
		}
	}
	return (answer + 1);
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> g_arr[i];
	}
	cout << solution() << '\n';
	return (0);
}
