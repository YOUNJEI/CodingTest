#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    static double ref[4] = {1.0, (double)3 / 2, 2.0, (double)4 / 3};
    
    sort(weights.begin(), weights.end());
    
    for (int i = 0; i < weights.size(); i++) {
        
        for (int r = 0; r < 4; r++) {
            int cur = lower_bound(weights.begin() + i + 1, weights.end(), 
                                  weights[i] * ref[r]) - weights.begin();
            if (weights[i] * ref[r] == weights[cur]) {
                while (cur < weights.size()) {
                    if (weights[i] * ref[r] != weights[cur])
                        break;
                    answer++;
                    cur++;
                }
            }
        }
    }
    
    return answer;
}
