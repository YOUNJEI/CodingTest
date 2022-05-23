#include <iostream>
using namespace std;

#define BUFFER_SIZE 100000000
#define INF 2100000000
int g_dp[BUFFER_SIZE + 1];

int min(int n1, int n2)
{
	if (n1 >= n2)
		return (n2);
	else
		return (n1);
}

int dfs(int n, int depth)
{
	static int answer = INF;

	if (n == 1)
	{
		answer = min(answer, depth);
		return (answer);
	}
	if (n % 5 == 0)
		dfs(n / 5, depth + 1);
	if (n % 3 == 0)
		dfs(n / 3, depth + 1);
	if (n % 2 == 0)
		dfs(n / 2, depth + 1);
	dfs(n - 1, depth + 1);
	return (answer);
}

int main(void)
{
	int X;
	cin>>X;
	g_dp[1] = 0;
	g_dp[2] = 1;
	g_dp[3] = 1;
	g_dp[4] = 2;
	g_dp[5] = 1;
	for (int i = 6; i <= X; i++)
	{
		int temp = INF;

		if (i % 5 == 0)
			temp = min(temp, g_dp[i / 5] + 1);
		else if (i % 3 == 0)
			temp = min(temp, g_dp[i / 3] + 1);
		else if (i % 2 == 0)
			temp = min(temp, g_dp[i / 2] + 1);
		g_dp[i] = min(temp, g_dp[i - 1] + 1);
	}
	cout<<"dp:"<<g_dp[X]<<"\n";
	cout<<"dfs:"<<dfs(X, 0)<<"\n";
	return (0);
}
