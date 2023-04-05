#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int g_col;

bool cmp(const vector<int>& v1, const vector<int>& v2) {
    if (v1[g_col - 1] == v2[g_col - 1])
        return v1[0] > v2[0];
    return v1[g_col - 1] < v2[g_col - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    g_col = col;
    
    sort(data.begin(), data.end(), cmp);
    vector<int> s;
    for (int i = row_begin - 1; i <= row_end - 1; i++) {
        int mod = 0;
        
        for (int j = 0; j < data[i].size(); j++) {
            mod += data[i][j] % (i + 1);
        }
        s.push_back(mod);
    }
    
    answer = s[0];
    for (int i = 1; i < s.size(); i++) {
        answer = answer ^ s[i];
    }
    return answer;
}
