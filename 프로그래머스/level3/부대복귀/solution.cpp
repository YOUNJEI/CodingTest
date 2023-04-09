#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
using namespace std;
#define BUFFER_SIZE 100000

vector<int> g_edges[BUFFER_SIZE + 1];
int g_dp[BUFFER_SIZE + 1];

void bfs(const int dest) {
    queue<pair<int, int>> q;    // now, dist
    unordered_set<int> visit;
    q.push({dest, 0});
    visit.insert(dest);
    
    while (!q.empty()) {
        int now = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        g_dp[now] = dist;
        for (int i = 0; i < g_edges[now].size(); i++) {
            if (visit.find(g_edges[now][i]) == visit.end()) {
                visit.insert(g_edges[now][i]);
                q.push({g_edges[now][i], dist + 1});
            }
        }
    }
}

void initEdges(const vector<vector<int>>& roads) {
    for (int i = 0; i < roads.size(); i++) {
        g_edges[roads[i][0]].push_back(roads[i][1]);
        g_edges[roads[i][1]].push_back(roads[i][0]);
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    initEdges(roads);
    bfs(destination);
    for (int i = 0; i < sources.size(); i++) {
        if (sources[i] == destination)
            answer.push_back(0);
        else if (g_dp[sources[i]] == 0)
            answer.push_back(-1);
        else
            answer.push_back(g_dp[sources[i]]);
    }
    return answer;
}
