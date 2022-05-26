#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define BUFFER_SIZE 10000

int g_arr[BUFFER_SIZE];
int g_dp[3][BUFFER_SIZE];
int N;

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> g_arr[i];
		g_dp[0][i] = g_arr[i];
		g_dp[1][i] = g_arr[i];
	}
	g_dp[2][0] = 0;

	for (int i = 1; i < N; i++)
	{
		g_dp[0][i] += g_dp[1][i - 1];
		g_dp[1][i] += g_dp[2][i - 1];
		g_dp[2][i] = max(max(g_dp[0][i - 1], g_dp[1][i - 1]), g_dp[2][i - 1]);
	}
	cout << max(max(g_dp[0][N - 1], g_dp[1][N - 1]), g_dp[2][N - 1])<< '\n';
	return (0);
}
