#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    int a = d / k;
    while (a >= 0) {
        int b = sqrt(((pow(d, 2) - pow(a * k, 2)) / (pow(k, 2))));
        answer += b + 1;
        a--;
    }
    return answer;
}
