#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int lastCur = 1;
    vector<pair<int, int>> noService;
    
    for (int i = 0; i < stations.size(); i++) {
        if (lastCur > n) {
            break;
        }
        if (lastCur < stations[i] - w) {
            noService.push_back(make_pair(lastCur, stations[i] - w - 1));
            lastCur = stations[i] + w + 1;
        }
        else {
            lastCur = stations[i] + w + 1;
        }
    }
    if (lastCur <= n) {
        noService.push_back(make_pair(lastCur, n));
    }
    for (int i = 0; i < noService.size(); i++) {
        int haveTo = noService[i].second - noService[i].first + 1;
        
        answer += haveTo / ((w * 2) + 1);
        if (haveTo % ((w * 2) + 1) != 0) {
            answer++;
        }
    }
    return answer;
}
