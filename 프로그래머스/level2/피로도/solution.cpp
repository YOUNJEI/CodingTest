#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int dfs(const vector<vector<int>>& dungeons, int k, unordered_set<int>& visit) {
    int answer = 0;
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (visit.find(i) == visit.end()) {
            if (k >= dungeons[i][0]) {
                visit.insert(i);
                answer = max(answer, dfs(dungeons, k - dungeons[i][1], visit));
                visit.erase(i);
            }
        }
    }
    return max(answer, (int)visit.size());
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    unordered_set<int> visit;
    answer = dfs(dungeons, k, visit);
    return answer;
}
