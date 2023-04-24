#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> tree) {
    int answer = 0;
    map<char, int> m;
    
    for (int i = 0; i < skill.length(); i++)
        m[skill[i]] = i;
    for (int i = 0; i < tree.size(); i++) {
        int lastIdx = -1;
        bool possible = true;
        for (int j = 0; j < tree[i].length(); j++) {
            if (m.find(tree[i][j]) != m.end()) {
                if (lastIdx + 1 != m[tree[i][j]]) {
                    possible = false;
                    break;
                }
                lastIdx = m[tree[i][j]];
            }
        }
        if (possible)
            answer++;
    }
    return answer;
}
