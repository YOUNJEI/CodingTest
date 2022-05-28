#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000
#define BUFFER_SIZE 100
int g_dp[BUFFER_SIZE + 1][BUFFER_SIZE + 1];
int N, M, X, K;

void resetdp(void)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				g_dp[i][j] = 0;
			else
				g_dp[i][j] = INF;
		}
	}
}

int solution(void)
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				g_dp[i][j] = min(g_dp[i][j], g_dp[i][k] + g_dp[k][j]);
			}
		}
	}
	if (g_dp[1][K] == INF || g_dp[K][X] == INF)
		return (-1);
	return (g_dp[1][K] + g_dp[K][X]);
}

int main(void)
{
	int temp[2];
	cin >> N >> M;
	resetdp();
	for (int i = 0; i < M; i++)
	{
		cin >> temp[0] >> temp[1];	// from to
		g_dp[temp[0]][temp[1]] = 1;
		g_dp[temp[1]][temp[0]] = 1;
	}
	cin >> X >> K;
	cout << solution() << '\n';
	return (0);
}
