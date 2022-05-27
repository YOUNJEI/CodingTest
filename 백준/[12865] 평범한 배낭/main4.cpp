#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define BUFFER_SIZE 100000
int g_dp[BUFFER_SIZE + 1];
vector<pair<int, int>> g_vector;
int N, K;

bool compare(const pair<int, int> p1, const pair<int, int> p2)
{
	return (p1.first < p2.first);
}

int main(void)
{
	int temp[2];
	int answer = 0;

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
		int temp = g_vector[i].first;
		for (int j = 0; j < i; j++)
		{
			temp += g_vector[j].first;
			g_dp[temp] = max(g_dp[temp], g_vector[j].second + g_dp[temp - g_vector[j].first]);
		}
	}
	for (int i = 0; i <= K; i++)
		answer = max(answer, g_dp[i]);
	cout << answer << '\n';
	return (0);
}
