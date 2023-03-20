#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    
    while (answer < enemy.size()) {
        n -= enemy[answer];
        pq.push(enemy[answer]);
        
        if (n < 0) {
            if (k < 1)
                return answer;
            while (n < 0 && k >= 1) {
                n += pq.top();
                pq.pop();
                k--;
            }
            if (n < 0)
                return answer;
        }
        answer++;
    }
    
    return answer;
}
