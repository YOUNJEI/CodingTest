#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char, int> x;
    map<char, int> y;
    
    for (int i = 0; i < X.length(); i++)
        x[X[i]]++;
    for (int i = 0; i < Y.length(); i++)
        y[Y[i]]++;
    
    stack<char> s;
    for (auto it = x.begin(); it != x.end(); it++) {
        auto it2 = y.find(it->first);
        if (it2 != y.end()) {
            int count = min(it->second, it2->second);
            for (int i = 0; i < count; i++)
                s.push(it->first);
        }
    }
    if (s.empty())
        return "-1";
    
    bool isZero = true;
    while (!s.empty()) {
        answer += s.top();
        if (s.top() != '0')
            isZero = false;
        s.pop();
    }
    
    if (isZero)
        return "0";
    return answer;
}
