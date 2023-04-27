#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    priority_queue<int> pq;
    answer.push_back(score[0]);
    pq.push(score[0]);
    for (int i = 1; i < score.size(); i++) {
        pq.push(score[i]);
        int temp = pq.top();
        priority_queue<int> restore;
        for (int j = 0; j < k && !pq.empty(); j++) {
            temp = pq.top();
            restore.push(temp);
            pq.pop();
        }
        answer.push_back(temp);
        while (!restore.empty()) {
            pq.push(restore.top());
            restore.pop();
        }
    }
    return answer;
}
