#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int getLength(const pair<int, int>& p) {
    return p.second - p.first + 1;
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int count = 0;
    queue<pair<int, int>> q;
    pair<int, int> temp = {0, 1000000};
    for (int i = 0; i < sequence.size(); i++) {
        count += sequence[i];
        q.push({sequence[i], i});
        
        if (count > k && !q.empty()) {
            while (count > k && !q.empty()) {
                count -= q.front().first;
                q.pop();
            }
        }
        if (count == k) {
            if (i - q.front().second + 1 < getLength(temp))
                temp = {q.front().second, i};
        }
    }
    answer.push_back(temp.first);
    answer.push_back(temp.second);
    return answer;
}
