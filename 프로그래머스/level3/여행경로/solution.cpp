#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

unordered_map<string, vector<string>> g_map;
unordered_map<string, unordered_set<int>> g_visit;

set<string> dfs(const vector<vector<string>>& tickets, const string& cur, string make, int count) {
    static set<string> ans;
    
    if (!ans.empty())
        return ans;
    
    if (count == tickets.size()) {
        ans.insert(make);
        return ans;
    }
    for (int i = 0; i < g_map[cur].size(); i++) {
        if (g_visit[cur].find(i) != g_visit[cur].end())
            continue;
        g_visit[cur].insert(i);
        dfs(tickets, g_map[cur][i], make + g_map[cur][i], count + 1);
        g_visit[cur].erase(i);
    }
    return ans;
}

vector<string> toConvert(const set<string>& tAns) {
    vector<string> answer;
    string s = *tAns.begin();
    string temp = "";
    
    for (int i = 0; i < s.length(); i++) {
        temp += s[i];
        if (temp.length() == 3) {
            answer.push_back(temp);
            temp = "";
        }
    }
    return answer;
}

vector<string> solution(vector<vector<string>> tickets) {
    for (int i = 0; i < tickets.size(); i++)
        g_map[tickets[i][0]].push_back(tickets[i][1]);
    for (auto it = g_map.begin(); it != g_map.end(); it++)
        sort(it->second.begin(), it->second.end());
    
    return toConvert(dfs(tickets, "ICN", "ICN", 0));
}
