#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string &s1, const string &s2) {
    int i;
    
    i = 0;
    while (i < s1.length() && i < s2.length()) {
        if (s1[i] != s2[i]) {
            return s1[i] > s2[i];
        }
        i++;
    }
    string left = s1 + s2;
    string right = s2 + s1;
    return stol(left) > stol(right);
}

string zeroException(const string &s) {
    int i;
    
    i = 0;
    while (i < s.length() && s[i] == '0') {
        i++;
    }
    if (i != s.length()) {
        return s.substr(i);
    }
    return "0";
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vs;
    
    for (int i = 0; i < numbers.size(); i++) {
        vs.push_back(to_string(numbers[i]));
    }
    sort(vs.begin(), vs.end(), compare);
    for (int i = 0; i < vs.size(); i++) {
        answer += vs[i];
    }
    answer = zeroException(answer);
    return answer;
}
