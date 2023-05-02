#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#define BUFFER_SIZE 100
using namespace std;

bool g_visit[BUFFER_SIZE + 1];
vector<int> g_edges[BUFFER_SIZE + 1];

int myAbs(const int t) {
    return t >= 0 ? t : -t;
}

int dfs(const int cur, unordered_set<int>& visit, const int except) {
    visit.insert(cur);
    
    for (int i = 0; i < g_edges[cur].size(); i++) {
        int toGo = g_edges[cur][i];
        if (toGo == except || visit.find(toGo) != visit.end())
            continue;
        dfs(toGo, visit, except);
    }
    return visit.size();
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    set<int> node;
    for (int i = 0; i < wires.size(); i++) {
        g_edges[wires[i][0]].push_back(wires[i][1]);
        g_edges[wires[i][1]].push_back(wires[i][0]);
        node.insert(wires[i][0]);
        node.insert(wires[i][1]);
    }
    for (auto it = node.begin(); it != node.end(); it++) {
        
        for (int i = 0; i < g_edges[*it].size(); i++) {
            unordered_set<int> visit[2];
            int left = dfs(*it, visit[0], g_edges[*it][i]);
            int right = dfs(g_edges[*it][i], visit[1], *it);
            int diff = myAbs(right - left);
            answer = min(answer, diff);
        }
    }
    return answer;
}
