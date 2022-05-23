#include <iostream>
#include <vector>
using namespace std;
#define BUFFER_SIZE 1000000
#define INF BUFFER_SIZE + 1
int g_dp[BUFFER_SIZE + 1];

int min(int n1, int n2)
{
	if (n1 >= n2)
		return (n2);
	else
		return (n1);
}

int main(void)
{
	int X;

	cin>>X;
	for (int i = 2; i <= X; i++)
	{
		g_dp[i] = INF;
		if (i % 3 == 0)
			g_dp[i] = min(g_dp[i], g_dp[i / 3] + 1);
		if (i % 2 == 0)
			g_dp[i] = min(g_dp[i], g_dp[i / 2] + 1);
		g_dp[i] = min(g_dp[i], g_dp[i - 1] + 1);
	}
	cout<<g_dp[X];
}
