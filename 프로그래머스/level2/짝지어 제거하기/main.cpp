#include <iostream>
#include<string>
#include <stack>
#include <utility>
using namespace std;

#define PAIR_LEN 2

int solve(const string &str) {
    stack<pair<char, int>> s;
    int i;
    
    i = 0;
    while (i < str.length()) {
        if (s.empty()) {
            s.push(make_pair(str[i], 1));
        }
        else {
            if (s.top().first == str[i]) {
                s.push(make_pair(str[i], s.top().second + 1));
            }
            else {
                s.push(make_pair(str[i], 1));
            }
        }
        while (!s.empty() && s.top().second == PAIR_LEN) {
            for (int j = 0; j < PAIR_LEN; j++) {
                s.pop();
            }
        }
        i++;
    }
    if (s.empty())
        return 1;
    else
        return 0;
}

int solution(string s)
{
    int answer = -1;
    
    answer = solve(s);
    return answer;
}
