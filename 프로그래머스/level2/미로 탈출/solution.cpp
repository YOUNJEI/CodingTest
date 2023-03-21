#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <queue>

#define BUFFER_SIZE 100
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];

using namespace std;

void resetQueue(queue<tuple<int, int, int>>& q) {
    while (!q.empty())
        q.pop();
}

void resetVisit(const vector<string>& maps) {
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].length(); j++) {
            g_visit[i][j] = false;
        }
    }
}

int bfs(const vector<string>& maps, int i, int j) {
    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};
    
    queue<tuple<int, int, int>> q;
    g_visit[i][j] = true;
    q.push({i, j, 0});
    
    int l = -1;
    while (!q.empty()) {
        int r = get<0>(q.front());
        int c = get<1>(q.front());
        int d = get<2>(q.front());
        q.pop();
        
        if (maps[r][c] == 'L') {
            l = d;
            i = r;
            j = c;
            break;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];
            
            if (nr >= 0 && nr < maps.size() && nc >= 0 && nc < maps[nr].length()) {
                if (!g_visit[nr][nc] && maps[nr][nc] != 'X') {
                    g_visit[nr][nc] = true;
                    q.push({nr, nc, d + 1});
                }
            }
        }
    }
    if (l == -1)
        return -1;
    
    resetVisit(maps);
    resetQueue(q);
    
    g_visit[i][j] = true;
    q.push({i, j, 0});
    
    int e = -1;
    while (!q.empty()) {
        int r = get<0>(q.front());
        int c = get<1>(q.front());
        int d = get<2>(q.front());
        q.pop();
        
        if (maps[r][c] == 'E') {
            e = d;
            break;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];
            
            if (nr >= 0 && nr < maps.size() && nc >= 0 && nc < maps[nr].length()) {
                if (!g_visit[nr][nc] && maps[nr][nc] != 'X') {
                    g_visit[nr][nc] = true;
                    q.push({nr, nc, d + 1});
                }
            }
        }
    }
    if (e == -1)
        return -1;
    return l + e;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].length(); j++) {
            if (maps[i][j] == 'S')
                answer = bfs(maps, i, j);
        }
    }
    return answer;
}
