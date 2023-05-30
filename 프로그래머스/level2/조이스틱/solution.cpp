#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define INF 1000000000
using namespace std;

int matchAlpha(const char& toBe, const char& now) {
    return min(toBe - now, 'Z' - toBe + now - 'A' + 1);
}

int dfs(const string& name, string now, int cur, int count, unordered_set<int>& visit) {
    static int ans = INF;
    
    if (visit.size() == name.length()) {
        count += matchAlpha(name[cur], now[cur]);
        ans = min(ans, count);
        return ans;
    }
    count += matchAlpha(name[cur], now[cur]);
    now[cur] = name[cur];
    
    int right = cur;
    int rightCount = 0;
    do {
        right++;
        rightCount++;
        while (right >= name.length())
            right -= name.length();
    } while (visit.find(right) != visit.end());
    visit.insert(right);
    dfs(name, now, right, count + rightCount, visit);
    visit.erase(right);
    
    int left = cur;
    int leftCount = 0;
    do {
        left--;
        leftCount++;
        while (left < 0)
            left += name.length();
    } while (visit.find(left) != visit.end());
    visit.insert(left);
    dfs(name, now, left, count + leftCount, visit);
    visit.erase(left);
    
    return ans;
}

int solution(string name) {
    int answer = 0;
    unordered_set<int> visit;
    string now = "";
    
    for (int i = 0; i < name.length(); i++) {
        now += "A";
        if (name[i] == 'A')
            visit.insert(i);
    }
    
    visit.insert(0);
    answer += dfs(name, now, 0, 0, visit);
    return answer;
}
