#include <string>
#include <vector>
#include <map>
using namespace std;

string charset = "AEIOU";
map<string, int> m;
void dfs(string make) {
    if (make != "")
        m[make] = m.size() + 1;
    if (make.length() == charset.length())
        return;
    for (int i = 0; i < charset.length(); i++)
        dfs(make + charset[i]);
}

int solution(string word) {
    int answer = 0;
    dfs("");
    return m[word];
}
