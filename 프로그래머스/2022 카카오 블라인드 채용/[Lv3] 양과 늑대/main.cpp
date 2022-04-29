#include <string>
#include <vector>
#include <queue>
#define BUFFER_SIZE 17

int g_edges[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE];

using namespace std;

void makeEdges(vector<vector<int>> &edges)
{
    int i;
    
    i = 0;
    while (i < edges.size())
    {
        g_edges[edges[i][0]][edges[i][1]] = 1;
        i++;
    }
}

int dfs(int cur, vector<int> q, vector<int> &info, int sheep, int wolf)
{
    static int answer = 0;
    int i;
    
    if (info[cur] == 0)
        sheep++;
    else
        wolf++;
    if (wolf >= sheep)
    {
        sheep = 0;
        return answer;
    }
    if (sheep > answer)
        answer = sheep;
    g_visit[cur] = true;
    i = 0;
    while (i < BUFFER_SIZE)
    {
        if (g_edges[cur][i])
            q.push_back(i);
        i++;
    }
    i = 0;
    while (i < BUFFER_SIZE)
    {
        if (g_edges[cur][i])
        {
            dfs(i, q, info, sheep, wolf);
            g_visit[i] = false;
        }
        i++;
    }
    i = 0;
    while (i < q.size())
    {
        if (g_visit[q[i]] == false)
        {
            dfs(q[i], q, info, sheep, wolf);
            g_visit[q[i]] = false;
        }
        i++;
    }
    return (answer);
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<int> q;
    
    makeEdges(edges);
    answer = dfs(0, q, info, 0, 0);
    return answer;
}
