#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool CanCross(vector<int> &stones, int k, int target);

int myMin(int n1, int n2) {
    if (n1 >= n2) {
        return n2;
    }
    else
        return n1;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int min = 1;
    int max = 200000000;
    
    while (min <= max) {
        int mid = (min + max) / 2;
        
        if (CanCross(stones, k, mid)) {
            min = mid + 1;
            if (mid > answer)
                answer = mid;
        }
        else {
            max = mid - 1;
        }
    }
    return answer;
}

bool CanCross(vector<int> &stones, int k, int target) {
    int step = 0;
    
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - target >= 0) {
            step = 0;
        }
        else {
            step++;
        }
        if (step >= k) {
            return (false);
        }
    }
    return (true);
}
