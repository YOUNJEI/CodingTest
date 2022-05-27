#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define BUFFER_SIZE 100000
#define ARRAY_SIZE 100
int g_dp[BUFFER_SIZE];
vector<pair<int, int>> g_vector;
int N, K;

bool compare(const pair<int, int> p1, const pair<int, int> p2)
{
	return (p1.first < p2.first);
}

int main(void)
{
	int temp[2];

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> temp[0] >> temp[1];
		g_dp[temp[0]] = temp[1];
		g_vector.push_back(make_pair(temp[0], temp[1]));
	}
	sort(g_vector.begin(), g_vector.end(), compare);
	for (int i = 0; i < N; i++)
	{
		g_dp[g_vector[i].first] = max(g_dp[g_vector[i].first], g_vector[i].second]);
		for (int j = 0; j < i; j++)
		{
			g_dp[g_vector[i].first] = max(g_dp[g_vector[i].first], g_dp[g_vector[i].first])
			for (int k = g_vector[j].first; k < g_vector[i].first; k++)
			{
				g_dp[k] = max(g_dp[k], g_vector[j].second + g_dp[k - g_vector[j].first]);
			}
		}
	}
}
