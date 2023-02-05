#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const int &i1, const int &i2) {
    return i1 > i2;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), compare);
    
    int minNum = 10;
    int c = 0;
    for (int i = 0; i < score.size(); i++) {
        if (c == m) {
            answer += minNum * m;
            c = 0;
        }
        minNum = min(minNum, score[i]);
        c++;
    }
    if (c == m)
        answer += minNum * m;
    return answer;
}
