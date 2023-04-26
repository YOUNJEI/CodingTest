#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

void add(vector<string>& possible, const vector<int> &c) {
    string str = "";
    for (int i = 0; i < c.size(); i++)
        str += c[i] + '0';
    possible.push_back(str);
}

bool isKey(const vector<vector<string>>& relation, const vector<int> &c) {
    unordered_set<string> us;
    
    for (int i = 0; i < relation.size(); i++) {
        string temp = "";
        for (int j = 0; j < c.size(); j++) {
            temp += relation[i][c[j]] + ":";
        }
        if (us.find(temp) != us.end())
            return false;
        us.insert(temp);
    }
    return true;
}

vector<string> dfs(const vector<vector<string>>& relation, vector<int> c) {
    static vector<string> possible;
    
    if (c.size() == 0) {
        possible.clear();
        for (int i = 0; i < relation[0].size(); i++) {
            vector<int> temp(c);
            temp.push_back(i);
            dfs(relation, temp);
        }
    } else {
        if (isKey(relation, c)) {
            add(possible, c);
            return possible;
        }
        int lastCur = c[c.size() - 1];
        for (int i = lastCur + 1; i < relation[0].size(); i++) {
            vector<int> temp(c);
            temp.push_back(i);
            dfs(relation, temp);
        }
    }
    return possible;
}

vector<string> checkUnique(vector<string>& possible) {
    vector<string> ans;
    
    for (int i = 0; i < possible.size(); i++) {
        unordered_set<char> us;
        for (int j = 0; j < possible[i].length(); j++)
            us.insert(possible[i][j]);
        
        bool toAdd = true;
        for (int j = 0; j < possible.size(); j++) {
            if (i == j)
                continue;
            if (possible[i].length() > possible[j].length()) {
                int count = 0;
                for (int k = 0; k < possible[j].length(); k++) {
                    if (us.find(possible[j][k]) != us.end())
                        count++;
                }
                if (count == possible[j].length()) {
                    toAdd = false;
                    break;
                }
            }
        }
        if (toAdd)
            ans.push_back(possible[i]);
    }
    return ans;
}

int solution(vector<vector<string>> relation) {
    vector<string> possible;
    possible = dfs(relation, vector<int>());
    possible = checkUnique(possible);
    return possible.size();
}
