#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define BUFFER_SIZE 10000
#define INF BUFFER_SIZE + 1
vector<pair<int, int>> g_edges[BUFFER_SIZE + 1];
int g_dist[BUFFER_SIZE + 1];
int N, D;

void initdist(void)
{
	for (int i = 1; i < BUFFER_SIZE + 1; i++)
		g_dist[i] = INF;
}

void dijkstra(void)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 0));	// dist km
	g_dist[0] = 0;

	while(!pq.empty())
	{
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = now; i <= D; i++)
		{
			// 지름길이 있다면
			if (g_edges[i].size() != 0)
			{
				for (int j = 0; j < g_edges[i].size(); j++)
				{

				}
			}
			else
			{

			}
		}
	}
}

int solution(void)
{
	int answer = INF;

	initdist();
	dijkstra();
	for (int i = D; i < BUFFER_SIZE + 1; i++)
		answer = min(answer, g_dist[i]);
	return (answer);
}

int main(void)
{
	int input[3];

	cin >> N >> D;
	for (int i = 0; i < N; i++)
	{
		cin >> input[0] >> input[1] >> input[2];
		g_edges[input[0]].push_back(make_pair(input[1], input[2]));
	}
	cout << solution() << '\n';
	return (0);
}
