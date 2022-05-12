#include <iostream>
using namespace std;

#define BUFFER_SIZE 300

int g_arr[BUFFER_SIZE][BUFFER_SIZE];
int g_temp[BUFFER_SIZE][BUFFER_SIZE];
int N, M, R;

int abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

// 1 UP 2 DOWN 3 LEFT 4 RIGHT
void dfs(int r, int c, int dir)
{
	switch (dir)
	{
		case 1:
			g_temp[r][c] = g_arr[r - 1][c];
			if (r + 1 < N - c)
				dfs(r + 1, c, 1);
			break;
			
		case 2:
			g_temp[r][c] = g_arr[r + 1][c];
			if (r - 1 >= (M - 1 - c))
				dfs(r - 1, c, 2);
			break;

		case 3:
			g_temp[r][c] = g_arr[r][c - 1];
			if (c + 1 < M - (N - r - 1))
				dfs(r, c + 1, 3);
			break;

		case 4:
			g_temp[r][c] = g_arr[r][c + 1];
			if (c - 1 >= r)
				dfs(r, c - 1, 4);
			break;

		case 0:
			g_temp[r + 1][c] = 0;
			break;
	}
	if (r == c && c <= (M - 1) / 2)
	{
		if (g_temp[r + 1][c] == 0)
			dfs(r + 1, c, 1);
		else if (c + 1 <= (M - 1) / 2)
			dfs(r + 1, c + 1, 0);
	}
	else if (r + c == N - 1 && c <= (M - 1) / 2)
		dfs(r, c + 1, 3);
	else if (r + c == M - 1 && c > (M - 1) / 2)
		dfs(r, c - 1, 4);
	else if (abs(c - r) == abs(M - N) && c > (M - 1) / 2)
		dfs(r - 1, c, 2);
}

void print(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout<<g_arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void resetTemp(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			g_arr[i][j] = g_temp[i][j];
		}
	}
}

void solution(void)
{
	for (int i = 0; i < R; i++)
	{
		dfs(0, 0, 0);
		resetTemp();
	}
	print();
}

int main(void)
{
	cin>>N>>M>>R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin>>g_arr[i][j];
		}
	}
	solution();
}
