#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define BUFFER_SIZE 100
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
using namespace std;

int bfs(const vector<string>& maps, const int i, const int j) {
    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    q.push({i, j});
    int days = 0;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        days += maps[r][c] - '0';
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];
            
            if (nr >= 0 && nr < maps.size() && nc >= 0 && nc < maps[nr].size()) {
                if (maps[nr][nc] != 'X' && !g_visit[nr][nc]) {
                    g_visit[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    return days;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] != 'X' && !g_visit[i][j]) {
                g_visit[i][j] = true;
                answer.push_back(bfs(maps, i, j));
            }
        }
    }
    if (answer.empty())
        return vector<int>({-1});
    sort(answer.begin(), answer.end());
    return answer;
}
