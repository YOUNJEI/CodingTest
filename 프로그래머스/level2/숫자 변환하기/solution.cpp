#include <string>
#include <vector>
#include <queue>
#include <set>
#include <utility>
using namespace std;

int bfs(const int x, const int y, const int n) {
    set<int> used;
    queue<pair<int, int>> q;
    int cur = x;
    
    if (cur * 3 <= y) {
        q.push({cur * 3, 1});
        used.insert(cur * 3);
    }
    if (cur * 2 <= y) {
        q.push({cur * 2, 1});
        used.insert(cur * 2);
    }
    if (cur + n <= y && used.find(cur + n) == used.end()) {
        q.push({cur + n, 1});
        used.insert(cur + n);
    }
    
    while (!q.empty()) {
        cur = q.front().first;
        int time = q.front().second;
        if (cur == y)
            return time;
        q.pop();
        
        if (cur * 3 <= y && used.find(cur * 3) == used.end()) {
            q.push({cur * 3, time + 1});
            used.insert(cur * 3);
        }
        if (cur * 2 <= y && used.find(cur * 2) == used.end()) {
            q.push({cur * 2, time + 1});
            used.insert(cur * 2);
        }
        if (cur + n <= y && used.find(cur + n) == used.end()) {
            q.push({cur + n, time + 1});
            used.insert(cur + n);
        }
    }
    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    if (x == y)
        return 0;
    answer = bfs(x, y, n);
    return answer;
}
