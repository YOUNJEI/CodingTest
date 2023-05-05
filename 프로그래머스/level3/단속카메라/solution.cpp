#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool cmp(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    
    unordered_set<int> us;
    us.insert(routes[0][1]);
    for (int i = 1; i < routes.size(); i++) {
        bool toAdd = true;
        for (auto it = us.begin(); it != us.end(); it++) {
            if (*it >= routes[i][0] && *it <= routes[i][1]) {
                toAdd = false;
                break;
            }
        }
        if (!toAdd)
            continue;
        us.insert(routes[i][1]);
    }
    return us.size();
}
