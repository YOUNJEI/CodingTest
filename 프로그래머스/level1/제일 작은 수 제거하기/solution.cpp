#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    priority_queue<int> pq;
    
    for (int i = 0; i < arr.size(); i++)
        pq.push(-arr[i]);
    int min = -pq.top();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != min)
            answer.push_back(arr[i]);
    }
    if (answer.size() == 0)
        answer.push_back(-1);
    return answer;
}
