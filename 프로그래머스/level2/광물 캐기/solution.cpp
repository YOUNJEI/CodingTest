#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define INF 1000000000
using namespace std;

int g_table[3][3] = {
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1}
};

bool allUsed(const vector<int>& picks, const pair<int, int>& use) {
    for (int i = 0; i < picks.size(); i++) {
        if (picks[i] > 0)
            return false;
    }
    if (use.first != 0 && use.first != 5)
        return false;
    return true;
}

int dfs(vector<int>& picks, const vector<string>& minerals, int cur, int piro, pair<int, int> use) {
    if (cur >= minerals.size() || allUsed(picks, use))
        return piro;
    
    int answer = INF;
    if (use.first == 5) {
        answer = min(answer, dfs(picks, minerals, cur, piro, {0, 0}));
    } else {
        int mineral = (minerals[cur] == "diamond") ? 0 : (minerals[cur] == "iron") ? 1 : 2;
        if (use.first == 0) {
            for (int i = 0; i < 3; i++) {
                if (picks[i] > 0) {
                    picks[i]--;
                    answer = min(answer, dfs(picks, minerals, cur + 1, piro + g_table[i][mineral], {1, i}));
                    picks[i]++;
                }
            }
        } else {
            answer = min(answer, dfs(picks, minerals, cur + 1, piro + g_table[use.second][mineral], {use.first + 1, use.second}));
        }
    }
    return answer;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    answer = dfs(picks, minerals, 0, 0, {0, 0});
    return answer;
}
