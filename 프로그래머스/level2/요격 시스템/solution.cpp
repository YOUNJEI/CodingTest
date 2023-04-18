#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool compare(const vector<int>& v1, const vector<int>& v2) {
    if (v1[0] == v2[0])
        return v1[1] > v2[1];
    return v1[0] < v2[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), compare);
    
    set<int> s;
    s.insert(targets[0][1]);
    answer++;
    for (int i = 1; i < targets.size(); i++) {
        int l = targets[i][0];
        int r = targets[i][1];
        
        if (l >= *s.begin()) {
            s.clear();
            answer++;
        }
        s.insert(r);
    }
    return answer;
}
