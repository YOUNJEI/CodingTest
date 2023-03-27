#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second > p2.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    
    for (int i = 0; i < tangerine.size(); i++)
        m[tangerine[i]]++;
    vector<pair<int, int>> vm(m.begin(), m.end());
    sort(vm.begin(), vm.end(), compare);
    
    int count = 0;
    for (int i = 0; i < vm.size(); i++) {
        count += vm[i].second;
        answer++;
        if (count >= k)
            break;
    }
    return answer;
}
