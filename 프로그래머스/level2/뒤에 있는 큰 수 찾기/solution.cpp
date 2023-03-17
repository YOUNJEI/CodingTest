#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void restore_stack(stack<int>& save, stack<int>& temp) {
    while (!temp.empty()) {
        save.push(temp.top());
        temp.pop();
    }
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> origin;
    stack<int> save;
    
    for (int i = 0; i < numbers.size(); i++)
        origin.push(numbers[i]);
    
    while (!origin.empty()) {
        int cur = origin.top();
        origin.pop();
        
        if (save.empty()) {
            answer.push_back(-1);
            save.push(cur);
            continue;
        }
        stack<int> temp;
        while (!save.empty() && save.top() <= cur) {
            temp.push(save.top());
            save.pop();
        }
        if (save.empty())
            answer.push_back(-1);
        else
            answer.push_back(save.top());
        //restore_stack(save, temp);
        save.push(cur);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
