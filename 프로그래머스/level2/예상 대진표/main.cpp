#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while (abs(a - b) != 1 || min(a, b) % 2 == 0) {
        a % 2 == 0 ? a /= 2 : a = (a / 2) + 1;
        b % 2 == 0 ? b /= 2 : b = (b / 2) + 1;
        answer++;
    }
    return answer + 1;
}
