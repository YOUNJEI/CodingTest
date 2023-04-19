#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
string g_charset = "";

string solution(string s, string skip, int index) {
    string answer = "";
    unordered_set<char> ss;
    unordered_map<char, int> m;
    
    for (int i = 0; i < skip.size(); i++)
        ss.insert(skip[i]);
    for (char c = 'a'; c <= 'z'; c++) {
        if (ss.find(c) != ss.end())
            continue;
        g_charset += c;
    }
    for (int i = 0; i < g_charset.length(); i++)
        m[g_charset[i]] = i;
    for (int i = 0 ; i < s.length(); i++) {
        int idx = m[s[i]] + index;
        while (idx >= m.size())
            idx -= m.size();
        answer += g_charset[idx];
    }
    return answer;
}
