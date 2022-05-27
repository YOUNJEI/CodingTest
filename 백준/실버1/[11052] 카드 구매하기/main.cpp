#include <iostream>
#include <algorithm>
using namespace std;
#define BUFFER_SIZE 1000
int g_dp[BUFFER_SIZE];
int N;

int main(void)
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> g_dp[i];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			g_dp[i] = max(g_dp[i], g_dp[i - j - 1] + g_dp[j]);
		}
	}
	cout << g_dp[N - 1];
	return (0);
}
