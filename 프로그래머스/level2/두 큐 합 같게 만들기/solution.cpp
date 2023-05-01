#include <string>
#include <vector>
#include <queue>
#define INF 300000
using namespace std;

long long g_count[2] = {0, 0};
queue<int> g_queue[2];

int queueAction(void) {
    int ans = 0;
    const long long target = (g_count[0] + g_count[1]) / 2;
    
    while (g_count[0] != g_count[1] && ans < INF) {
        if (g_count[0] > target) {
            if (g_queue[0].empty())
                return -1;
            g_count[0] -= g_queue[0].front();
            g_count[1] += g_queue[0].front();
            g_queue[1].push(g_queue[0].front());
            g_queue[0].pop();
        } else {
            if (g_queue[1].empty())
                return -1;
            g_count[1] -= g_queue[1].front();
            g_count[0] += g_queue[1].front();
            g_queue[0].push(g_queue[1].front());
            g_queue[1].pop();
        }
        ans++;
    }
    return ans == INF ? -1 : ans;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    
    for (int i = 0; i < queue1.size(); i++) {
        g_count[0] += queue1[i];
        g_queue[0].push(queue1[i]);
    }
    for (int i = 0; i < queue2.size(); i++) {
        g_count[1] += queue2[i];
        g_queue[1].push(queue2[i]);
    }
    if ((g_count[0] + g_count[1]) % 2 != 0)
        return -1;
    answer = queueAction();
    return answer;
}
