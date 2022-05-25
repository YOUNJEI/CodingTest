#include <iostream>
using namespace std;
#define BUFFER_SIZE 1000
#define INF BUFFER_SIZE + 1

int g_dp[3][BUFFER_SIZE];

int min(int n1, int n2)
{
	if (n1 >= n2)
		return (n2);
	else
		return (n1);
}

int main(void)
{
	int N;

	cin >> N;
	for (int i = 0; i < 3; i++)
		cin >> g_dp[i][0];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> g_dp[j][i];

			int temp;
			switch (j)
			{
				case 0:
					temp = g_dp[1][i - 1];
					temp = min(temp, g_dp[2][i - 1]);
					break ;
					
				case 1:
					temp = g_dp[0][i - 1];
					temp = min(temp, g_dp[2][i - 1]);
					break ;

				case 2:
					temp = g_dp[0][i - 1];
					temp = min(temp, g_dp[1][i - 1]);
					break;
			}
			g_dp[j][i] += temp;
		}
	}
	int temp = g_dp[0][N - 1];
	for (int i = 1; i < 3; i++)
		temp = min(temp, g_dp[i][N - 1]);
	cout<<temp<<'\n';
	return (0);
}
