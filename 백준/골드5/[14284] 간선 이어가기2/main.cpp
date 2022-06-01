#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define BUFFER_SIZE 5000
#define INF 1000000000

vector<pair<int, int>> g_edges[BUFFER_SIZE + 1];
int g_dist[BUFFER_SIZE + 1];
int N, M, S, T;

void initdist(void)
{
	for (int i = 1; i <= N; i++)
		g_dist[i] = INF;
}

void dijkstra(void)
{
	priority_queue<pair<int, int>> pq;
	g_dist[S] = 0;
	pq.push(make_pair(0, S));

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
	initdist();
	dijkstra();
	return (g_dist[T]);
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
	cin >> S >> T;
	cout << solution() << '\n';
	return (0);
}
