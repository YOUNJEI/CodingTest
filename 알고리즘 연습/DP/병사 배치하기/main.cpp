#include <iostream>
#include <vector>
using namespace std;
#define BUFFER_SIZE 2000

int g_dp[BUFFER_SIZE] = {0, };

int main(void)
{
	int N;
	vector<int> vi;
	int answer = 0;

	cin>>N;
	for (int i = 0; i < N; i++)
	{
		g_dp[i] = 1;
		int temp;
		cin>>temp;
		vi.push_back(temp);
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vi[j] >= vi[i])
				g_dp[i] = max(g_dp[i], g_dp[j] + 1);
		}
	}
	for (int i = 0; i < N; i++)
		answer = max(answer, g_dp[i]);
	cout<<N - answer;
	return (0);
}
