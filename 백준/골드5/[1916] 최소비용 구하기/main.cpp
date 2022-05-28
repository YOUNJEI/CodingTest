#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define INF 1000000000
#define BUFFER_SIZE 1000
vector<pair<int, int>> g_edges[BUFFER_SIZE + 1];
int g_dist[BUFFER_SIZE + 1];
int N, M, A, B;

void distinit(void)
{
	for (int i = 1; i <= N; i++)
		g_dist[i] = INF;
}

// dijkstra(int start)
// start is A
void dijkstra(void)
{
	priority_queue<pair<int, int>> pq;
	g_dist[A] = 0;
	pq.push(make_pair(0, A));

	while(!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist > g_dist[now])
			continue ;

		for (int i = 0; i < g_edges[now].size(); i++)
		{
			int cost = dist + g_edges[now][i].second;

			// 값을 갱신
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
	distinit();
	dijkstra();	// dijkstra(A)
	return (g_dist[B]);
}

int main(void)
{
	int input[3];

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> input[0] >> input[1] >> input[2];
		g_edges[input[0]].push_back(make_pair(input[1], input[2]));
	}
	cin >> A >> B;
	cout << solution() << '\n';
	return (0);
}
