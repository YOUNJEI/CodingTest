#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define INF 1000000000
#define BUFFER_SIZE 20000
vector<pair<int, int>> g_edges[BUFFER_SIZE + 1];
int g_dist[BUFFER_SIZE + 1];
int V, E, K;

void resetdist(void)
{
	for (int i = 1; i <= V; i++)
		g_dist[i] = INF;
}

void dijkstra(void)
{
	priority_queue<pair<int, int>> pq;
	g_dist[K] = 0;
	pq.push(make_pair(0, K));
	
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

vector<int> solution(void)
{
	vector<int> answer;

	resetdist();
	dijkstra();
	for (int i = 1; i <= V; i++)
		answer.push_back(g_dist[i]);
	return (answer);
}

int main(void)
{
	int input[3];
	vector<int> vi;

	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++)
	{
		cin >> input[0] >> input[1] >> input[2];
		g_edges[input[0]].push_back(make_pair(input[1], input[2]));
	}
	vi = solution();
	for (int i = 0; i < vi.size(); i++)
	{
		if (vi[i] == INF)
			cout<<"INF\n";
		else
			cout<<vi[i]<<'\n';
	}
	return (0);
}
