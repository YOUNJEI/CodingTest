#include <iostream>
#include <vector>
using namespace std;

#define BUFFER_SIZE 20
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
int g_dp[BUFFER_SIZE][BUFFER_SIZE];
int dx[] = {-1, 0, 1};

int max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

void reset(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			g_arr[i][j] = 0;
			g_dp[i][j] = 0;
		}
	}
}

int solution(int n, int m)
{
	for (int r = 0; r < n; r++)
		g_dp[r][0] = g_arr[r][0];
	for (int c = 1; c < m; c++)
	{
		for (int r = 0; r < n; r++)
		{
			int temp = 0;

			for (int dir = 0; dir < 3; dir++)
			{
				int nr = r + dx[dir];

				if (nr >= 0 && nr < n)
					temp = max(temp, g_dp[nr][c - 1]);
			}
			g_dp[r][c] = temp + g_arr[r][c];
		}
	}
	int temp = 0;
	for (int r = 0; r < n; r++)
		temp = max(temp, g_dp[r][m - 1]);
	return (temp);
}

int main(void)
{
	int T;
	vector<int> answer;

	cin>>T;
	for (int t = 0; t < T; t++)
	{
		int n, m;

		cin>>n>>m;
		reset(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin>>g_arr[i][j];
			}
		}
		answer.push_back(solution(n, m));
	}
	for (int i = 0; i < answer.size(); i++)
		cout<<answer[i]<<'\n';
	return (0);
}
