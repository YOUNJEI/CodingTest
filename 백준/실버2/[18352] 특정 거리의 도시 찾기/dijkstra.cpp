#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define INF 100000000
#define BUFFER_SIZE 300000
vector<int> g_edges[BUFFER_SIZE + 1];
int g_dist[BUFFER_SIZE + 1];
int N, M, K, X;

void distinit(void)
{
	for (int i = 1; i <= N; i++)
		g_dist[i] = INF;
}

void dijkstra(void)
{
	priority_queue<pair<int, int>> pq;
	g_dist[X] = 0;
	pq.push(make_pair(0, X));

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist > g_dist[now])
			continue ;
		for (int i = 0; i < g_edges[now].size(); i++)
		{
			int cost = dist + 1;

			if (cost < g_dist[g_edges[now][i]])
			{
				g_dist[g_edges[now][i]] = cost;
				pq.push(make_pair(-cost, g_edges[now][i]));
			}
		}
	}
}

vector<int> solution(void)
{
	vector<int> answer;

	distinit();
	dijkstra();
	for (int i = 1; i <= N; i++)
	{
		if (g_dist[i] == K)
			answer.push_back(i);
	}
	return (answer);
}

int main(void)
{
	int A, B;
	vector<int> answer;
	
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		g_edges[A].push_back(B);
	}
	answer = solution();
	if (answer.size() == 0)
		cout << "-1\n";
	else
	{
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << '\n';
	}
	return (0);
}
