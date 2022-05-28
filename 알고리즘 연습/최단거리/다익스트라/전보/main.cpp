#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define INF 2000000000
#define BUFFER_SIZE 30000
vector<pair<int, int>> g_edge[BUFFER_SIZE + 1];
int g_dp[BUFFER_SIZE + 1];
int N, M, C;

void resetdp(void)
{
	for (int i = 0; i < N; i++)
	{
		g_dp[i] = INF;
	}
}

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	g_dp[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int dist = -pq.top().first;	// 간선 비용
		int now = pq.top().second;	// 현재 처리하고 있는 노드
		pq.pop();

		if (dist > g_dp[now])
			continue ;
		for (int i = 0; i < g_edge[now].size(); i++)
		{
			int cost = dist + g_edge[now][i].second;

			if (g_dp[g_edge[now][i].first] > cost)
			{
				g_dp[g_edge[now][i].first] = cost;
				pq.push(make_pair(-cost, g_edge[now][i].first));
			}
		}
	}
}

pair<int, int> solution(void)
{
	int count = 0;
	int time = 0;

	resetdp();
	dijkstra(C);	// start C
	for (int i = 0; i < N; i++)
	{
		if (g_dp[i] == INF)
			continue ;
		count++;
		time = max(time, g_dp[i]);
	}
	return (make_pair(count, time));
}

int main(void)
{
	int temp[3];

	cin >> N >> M >> C;
	for (int i = 0; i < M; i++)
	{
		cin >> temp[0] >> temp[1] >> temp[2];	// from to cost
		g_edge[temp[0]].push_back(make_pair(temp[1], temp[2]));	// to cost
	}
	pair<int, int> p = solution();
	cout << p.first << " " << p.second << '\n';
	return (0);
}
