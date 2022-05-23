#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define BUFFER_SIZE 40
pair<int, int> g_dp[BUFFER_SIZE + 1];

int main(void)
{
	int T;
	vector<pair<int, int>> answer;

	g_dp[0] = make_pair(1, 0);
	g_dp[1] = make_pair(0, 1);
	cin>>T;
	for (int i = 0; i < T; i++)
	{
		int n;

		cin>>n;
		for (int j = 2; j <= n; j++)
			g_dp[j] = make_pair(g_dp[j - 1].second, g_dp[j - 1].first + g_dp[j - 1].second);
		answer.push_back(make_pair(g_dp[n].first, g_dp[n].second));
	}
	for (int i = 0; i < T; i++)
		cout<<answer[i].first<<" "<<answer[i].second<<'\n';
	return (0);
}
