#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int> &number, int idx, int left, int score) {
    static int answer = 0;
    
    if (left == 0) {
        if (score == 0) {
            answer++;
        }
        return answer;
    }
    if (idx < number.size()) {
        dfs(number, idx + 1, left - 1, score + number[idx]);
        dfs(number, idx + 1, left, score);
    }
    return answer;
}

int solution(vector<int> number) {
    int answer = 0;
    answer = dfs(number, 0, 3, 0);
    return answer;
}
