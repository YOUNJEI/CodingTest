#include <string>
#include <vector>
#include <algorithm>
#define BUFFER_SIZE 50
#define INF 1000000000
bool g_visit[BUFFER_SIZE];
using namespace std;

int check(const string& cur, const string& word) {
    int c = 0;
    for (int i = 0; i < cur.length(); i++) {
        if (cur[i] != word[i]) {
            c++;
        }
    }
    return c;
}

int dfs(string cur, const string& target, const vector<string>& words, int count) {
    static int ans = INF;
    
    if (count >= ans)
        return ans;
    if (cur == target)
        ans = min(ans, count);
    
    for (int i = 0; i < words.size(); i++) {
        if (g_visit[i])
            continue;
        int c = check(cur, words[i]);
        if (c != 1)
            continue;
        g_visit[i] = true;
        dfs(words[i], target, words, count + 1);
        g_visit[i] = false;
    }
    
    if (ans == INF)
        return 0;
    return ans;
}

int solution(string begin, string target, vector<string> words) {
    return dfs(begin, target, words, 0);
}
