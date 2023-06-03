#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    
    for (int i = 0; i < scoville.size(); i++)
        pq.push(-scoville[i]);
    while (pq.size() >= 2) {
        auto low1 = -pq.top();
        pq.pop();
        if (low1 >= K)
            return answer;
        
        auto low2 = -pq.top();
        pq.pop();
        
        int newScoville = low1 + (low2 * 2);
        pq.push(-newScoville);
        answer++;
    }
    if (-pq.top() >= K)
        return answer;
    return -1;
}
