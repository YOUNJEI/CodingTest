#include <iostream>
#include <vector>
using namespace std;
#define BUFFER_SIZE 10
int g_dp[BUFFER_SIZE + 1];

int main(void)
{
	int T;
	int n;
	vector<int> vi;

	cin>>T;
	for (int t = 0; t < T; t++)
	{
		cin>>n;
		g_dp[0] = 0;
		g_dp[1] = 1;
		g_dp[2] = 2;
		g_dp[3] = 4;

		if (g_dp[n] == 0)
		{
			for (int i = 4; i <= n; i++)
			{
				if (g_dp[i] != 0)
					continue ;
				g_dp[i] += g_dp[i - 1];
				g_dp[i] += g_dp[i - 2];
				g_dp[i] += g_dp[i - 3];
			}
		}
		vi.push_back(g_dp[n]);
	}
	for (int i = 0; i < vi.size(); i++)
		cout<<vi[i]<<'\n';
	return (0);
}
