#include <iostream>
#include <vector>
using namespace std;
#define BUFFER_SIZE 100
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
	vector<int> vi;

	cin>>N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin>>temp;
		vi.push_back(temp);
	}
	g_dp[0] = vi[0];
	g_dp[1] = max(vi[0], vi[1]);

	for (int i = 2; i < N; i++)
		g_dp[i] = max(g_dp[i - 1], g_dp[i - 2] + vi[i]);
	cout<<g_dp[N - 1];
	return (0);
}
