#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> m;
    
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].length(); j++) {
            if (m[keymap[i][j]] == 0)
                m[keymap[i][j]] = j + 1;
            else if (j + 1 < m[keymap[i][j]])
                m[keymap[i][j]] = j + 1;
        }
    }
    for (int i = 0; i < targets.size(); i++) {
        int count = 0;
        for (int j = 0; j < targets[i].length(); j++) {
            if (m[targets[i][j]] == 0) {
                count = -1;
                break;
            }
            count += m[targets[i][j]];
        }
        answer.push_back(count);
    }
    return answer;
}
