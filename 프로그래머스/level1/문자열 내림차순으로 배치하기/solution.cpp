#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(string s) {
    string answer = "";
    priority_queue<char> pq;
    
    for (int i = 0; i < s.length(); i++)
        pq.push(s[i]);
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }
    return answer;
}
