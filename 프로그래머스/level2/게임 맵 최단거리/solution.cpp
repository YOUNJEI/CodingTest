#include <vector>
#include <queue>
#include <tuple>
#define BUFFER_SIZE 100
using namespace std;

bool g_visit[BUFFER_SIZE][BUFFER_SIZE];

int bfs(const vector<vector<int>>& maps) {
    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};
    
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 1});
    g_visit[0][0] = true;
    
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        
        if (get<0>(front) == maps.size() - 1 && get<1>(front) == maps[maps.size() - 1].size() - 1)
            return get<2>(front);
        for (int dir = 0; dir < 4; dir++) {
            int nr = get<0>(front) + dx[dir];
            int nc = get<1>(front) + dy[dir];
            
            if (nr >= 0 && nr < maps.size() && nc >= 0 && nc < maps[nr].size() && maps[nr][nc] == 1 && !g_visit[nr][nc]) {
                g_visit[nr][nc] = true;
                q.push({nr, nc, get<2>(front) + 1});
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps) {
    return bfs(maps);
}
