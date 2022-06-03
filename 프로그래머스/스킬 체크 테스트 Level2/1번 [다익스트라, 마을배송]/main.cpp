#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define BUFFER_SIZE 50
#define INF 1000000000

vector<pair<int, int>> g_edges[BUFFER_SIZE + 1];    // Node, dist
int g_dist[BUFFER_SIZE + 1];

void init(int N, vector<vector<int>> &road)
{
    // init g_dist
    for (int i = 1; i <= N; i++)
        g_dist[i] = INF;
    
    // init g_edges
    for (int i = 0; i < road.size(); i++)
    {
        g_edges[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        g_edges[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
}

void dijkstra(void)
{
    priority_queue<pair<int, int>> pq;  // cost, now
    pq.push(make_pair(0, 1));           // pq init -> cost: 0, now: 1
    g_dist[1] = 0;
    
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

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    // init g_edges and g_dist
    init(N, road);
    // dijkstra
    dijkstra();
    
    // count answer
    for (int i = 1; i <= N; i++)
    {
        if (g_dist[i] <= K)
            answer++;
    }
    return (answer);
}