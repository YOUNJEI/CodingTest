#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define BUFFER_SIZE 100000
#define N_BUFFER 100
int g_dp[BUFFER_SIZE + 1];
bool g_visit[N_BUFFER + 1];
vector<pair<int, int>> g_vector;
int N, K;

bool compare(const pair<int, int> p1, const pair<int, int> p2)
{
	return (p1.first < p2.first);
}

void calculatedp(void)
{
	int cur = 0;
	int lastIdx = -1;
	for (int i = 0; i < N; i++)
	{
		if (g_visit[i])
		{
			cur += g_vector[i].first;
			lastIdx = i;
		}
	}
	if (cur < BUFFER_SIZE - 1 && lastIdx != -1)
		g_dp[cur] = max(g_dp[cur], g_dp[cur - g_vector[lastIdx].first] + g_vector[lastIdx].second);
}

void makedp(int idx)
{
	for (int i = idx; i < N; i++)
	{
		g_visit[i] = true;
		calculatedp();
		makedp(i + 1);
		g_visit[i] = false;
	}
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
	makedp(0);
	/*
	for (int i = 0; i < N; i++)
	{
		int prev = g_vector[i].first;
		int cur = g_vector[i].first;
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue ;
			cur += g_vector[j].first;
			if (cur < BUFFER_SIZE + 1)
			{
				g_dp[cur] = max(g_dp[cur], g_dp[prev] + g_vector[j].second);
				prev = cur;
			}
			else
				break ;
		}
	}
	*/
	for (int i = 0; i <= K; i++)
		answer = max(answer, g_dp[i]);
	cout << answer << '\n';
	return (0);
}
