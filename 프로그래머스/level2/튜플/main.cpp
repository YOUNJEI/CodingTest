#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

map<int, int> solve(const string &s) {
    map<int, int> m;
    int i, num;
    
    i = 0;
    string temp = "";
    while (i < s.length()) {
        if (s[i] == ',') {
            num = stoi(temp);
            
            if (m.find(num) != m.end()) {
                m[num]++;
            }
            else {
                m[num] = 1;
            }
            temp = "";
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            temp += s[i];
        }
        i++;
    }
    num = stoi(temp);
    if (m.find(num) != m.end()) {
        m[num]++;
    }
    else {
        m[num] = 1;
    }
    return m;
}

bool compare(const pair<int, int> &k1, const pair<int, int> &k2) {
    return k1.second > k2.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    map<int, int> m = solve(s);
    vector<pair<int, int>> haveToSort(m.begin(), m.end());
    sort(haveToSort.begin(), haveToSort.end(), compare);
    for (int i = 0; i < haveToSort.size(); i++) {
        answer.push_back(haveToSort[i].first);
    }
    return answer;
}
