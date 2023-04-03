#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <iostream>
using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<pair<int, pair<string, int>>> pq;
    
    for (int i = 0; i < plans.size(); i++) {
        int start = stoi(plans[i][1].substr(0, 2) + plans[i][1].substr(3, 2));
        int startHour = start / 100;
        int startMin = start - (startHour * 100);
        
        pq.push({-(startHour * 60 + startMin), {plans[i][0], stoi(plans[i][2])}});
    }
    
    stack<pair<string, int>> temp;
    pair<int, pair<string, int>> last = pq.top();
    pq.pop();
    while (!pq.empty()) {
        int start = -pq.top().first;
        string subject = pq.top().second.first;
        int playtime = pq.top().second.second;
        auto t = pq.top();
        pq.pop();
        
        if ((-last.first + last.second.second) > start) {
            temp.push({last.second.first, last.second.second - (start + last.first)});
        } else {
            answer.push_back(last.second.first);
        }
        
        if (!temp.empty()) {
            int diffTime = start - (-last.first + last.second.second);
            
            while (diffTime > 0 && !temp.empty()) {
                auto st = temp.top();
                temp.pop();
                if (diffTime < st.second) {
                    temp.push({st.first, st.second - diffTime});
                    diffTime = 0;
                } else {
                    answer.push_back(st.first);
                    diffTime -= st.second;
                }
            }
        }
        last = t;
    }
    answer.push_back(last.second.first);
    while (!temp.empty()) {
        answer.push_back(temp.top().first);
        temp.pop();
    }
    return answer;
}
