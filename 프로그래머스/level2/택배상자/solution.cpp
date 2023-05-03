#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    queue<int> q;
    
    for (int i = 0; i < order.size(); i++)
        q.push(order[i]);
    for (int i = 1; i <= 1000000 && !q.empty(); i++) {
        if (q.front() != i) {
            s.push(i);
            continue;
        }
        answer++;
        q.pop();
        
        while (!q.empty() && !s.empty()) {
            if (q.front() == s.top()) {
                answer++;
                q.pop();
                s.pop();
            } else if (q.front() < s.top()) {
                return answer;
            } else
                break;
        }
        if (q.empty())
            break;
    }
    return answer;
}
