#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> q1;
    queue<string> q2;
    for (int i = 0; i < cards1.size(); i++)
        q1.push(cards1[i]);
    for (int i = 0 ; i < cards2.size(); i++)
        q2.push(cards2[i]);
    
    for (int i = 0; i < goal.size(); i++) {
        if (!q1.empty()) {
            if (q1.front() == goal[i]) {
                q1.pop();
                continue;
            }
        }
        if (!q2.empty()) {
            if (q2.front() == goal[i]) {
                q2.pop();
                continue;
            }
        }
        return "No";
    }
    return "Yes";
}
