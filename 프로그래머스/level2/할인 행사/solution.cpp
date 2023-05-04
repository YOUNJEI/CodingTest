#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    
    for (int i = 0; i < want.size(); i++) {
        m[want[i]] = number[i];
    }
    for (int i = 0; i < discount.size(); i++) {
        map<string, int> m2;
        for (int j = i; j < discount.size() && j < i + 10; j++) {
            m2[discount[j]]++;
        }
        bool possible = true;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (m2[it->first] < it->second) {
                possible = false;
                break;
            }
        }
        if (possible) {
            answer++;
        }
    }
    return answer;
}
