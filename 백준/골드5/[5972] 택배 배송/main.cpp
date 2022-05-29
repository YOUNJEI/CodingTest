#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define INF 1000000000
#define BUFFER_SIZE 50000
vector<pair<int, int>> g_edges[BUFFER_SIZE + 1];
int g_dist[BUFFER_SIZE + 1];
int N, M;

void initdist(void)
{
	for (int i = 1; i <= N; i++)
		g_dist[i] = INF;
}

void dijkstra(void)
{
	priority_queue<pair<int, int>> pq;	// dist, now
	g_dist[1] = 0;
	pq.push(make_pair(0, 1));

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist > g_dist[now])
			continue ;
		for (int i = 0; i < g_edges[now].size(); i++)
		{
			int cost = dist + g_edges[now][i].second;

			if (cost < g_dist[g_edges[now][i].first])
			{
				g_dist[g_edges[now][i].first] = cost;
				pq.push(make_pair(-cost, g_edges[now][i].first));
			}
		}
	}
}

int solution(void)
{
	int answer = 0;

	initdist();
	dijkstra();

	if (g_dist[N] == INF)
		return (-1);
	else
		return (g_dist[N]);
}

int main(void)
{
	int input[3];

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> input[0] >> input[1] >> input[2];
		g_edges[input[0]].push_back(make_pair(input[1], input[2]));
		g_edges[input[1]].push_back(make_pair(input[0], input[2]));
	}
	cout << solution() << '\n';
	return (0);
}
