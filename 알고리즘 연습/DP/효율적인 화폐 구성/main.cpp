#include <iostream>
#include <vector>
using namespace std;

#define BUFFER_SIZE 10000
#define INF 2000000000
int g_dp[BUFFER_SIZE + 1] = {INF,};
int g_temp = INF;

int min(int n1, int n2)
{
	if (n1 > n2)
		return (n2);
	else
		return (n1);
}

int main(void)
{
	int N, M;
	vector<int> vi;

	cin>>N>>M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin>>temp;
		vi.push_back(temp);
	}
	g_dp[0] = 0;
	for (int i = 1; i <= M; i++)
	{
		int temp = INF;
		for (int j = 0; j < vi.size(); j++)
		{
			if (i - vi[j] >= 0)
				temp = min(temp, g_dp[i - vi[j]]);
		}
		g_dp[i] = temp;
		if (temp != INF)
			g_dp[i]++;
	}
	if (g_dp[M] != INF)
		cout<<g_dp[M]<<endl;
	else
		cout<<-1<<endl;
	return (0);
}
