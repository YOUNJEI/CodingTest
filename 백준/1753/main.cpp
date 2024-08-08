#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define BUFFER_SIZE 20000
#define INF 100000000
vector<pair<int, int>> g_edges[BUFFER_SIZE + 1];
int g_dist[BUFFER_SIZE + 1];

int V, E, K;

void dijkstra() {
	priority_queue<pair<int, int>> pq;	// now cost
	pq.push({0, K});
	g_dist[K] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist > g_dist[now])
			continue;

		for (int i = 0; i < g_edges[now].size(); i++) {
			int cost = dist + g_edges[now][i].second;

			if (cost < g_dist[g_edges[now][i].first]) {
				g_dist[g_edges[now][i].first] = cost;
				pq.push({-cost, g_edges[now][i].first});
			}
		}
	}
}

int main(void) {
	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		int s, f, d;

		cin >> s >> f >> d;
		g_edges[s].push_back({f, d});
	}
	for (int i = 1; i <= V; i++)
		g_dist[i] = INF;
	dijkstra();
	for (int i = 1; i <= V; i++) {
		if (g_dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << g_dist[i] << "\n";
	}
	return 0;
}
