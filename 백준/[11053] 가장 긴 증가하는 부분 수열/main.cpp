#include <iostream>
using namespace std;
#define BUFFER_SIZE 1000
int g_arr[BUFFER_SIZE];
int g_dp[BUFFER_SIZE];

int max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

int main(void)
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> g_arr[i];
	for (int i = 0; i < N; i++)
	{
		g_dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (g_arr[i] > g_arr[j])
				g_dp[i] = max(g_dp[i], g_dp[j] + 1);
		}
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
		answer = max(answer, g_dp[i]);
	cout<<answer<<'\n';
	return (0);
}
