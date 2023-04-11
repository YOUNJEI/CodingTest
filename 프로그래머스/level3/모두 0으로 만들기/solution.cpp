#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define BUFFER_SIZE 300000
long long g_node[BUFFER_SIZE];
vector<int> g_edges[BUFFER_SIZE];
bool g_visit[BUFFER_SIZE];
long long g_answer = 0;

long long dfs(const int cur) {
    g_visit[cur] = true;
    
    long long curWeight = g_node[cur];
    
    long long childWeight = 0;
    for (int i = 0; i < g_edges[cur].size(); i++) {
        if (!g_visit[g_edges[cur][i]]) {
            long long temp = dfs(g_edges[cur][i]);
            g_answer += abs(temp);
            childWeight += temp;
        }
    }
    curWeight -= childWeight;
    return -curWeight;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long result = -2;
    
    for (int i = 0; i < a.size(); i++)
        g_node[i] = a[i];
    for (int i = 0; i < edges.size(); i++) {
        g_edges[edges[i][0]].push_back(edges[i][1]);
        g_edges[edges[i][1]].push_back(edges[i][0]);
    }
    result = dfs(0);
    if (result != 0)
        return -1;
    return g_answer;
}
