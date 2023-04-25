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

bool cmp(const string &s1, const string &s2) {
    return s1.length() < s2.length();
}

vector<string> checkUnique(vector<string>& possible) {
    sort(possible.begin(), possible.end(), cmp);
    
    vector<string> ans;
    ans.push_back(possible[0]);
    for (int i = 1; i < possible.size(); i++) {
        bool isUnique = true;
        for (int j = 0; j < ans.size(); j++) {
            if (possible[i].find(ans[j]) != string::npos) {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
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
