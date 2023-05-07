#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> s;
    
    int del = 0;
    for (int i = 0; i < number.length(); i++) {
        while (!s.empty() && number[i] > s.top() && del < k) {
            s.pop();
            del++;
        }
        s.push(number[i]);
    }
    while (del < k) {
        s.pop();
        del++;
    }
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
