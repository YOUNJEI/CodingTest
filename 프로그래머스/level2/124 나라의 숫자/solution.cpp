#include <string>
#include <vector>
#include <iostream>
using namespace std;

char g_charset[3] = {'1', '2', '4'};

string convert(int n) {
    string answer = "";
    
    if (n >= 3) {
        answer += convert((n / 3) - 1);
    }
    answer += g_charset[n % 3];
    return answer;
}

string solution(int n) {
    string answer = "";
    
    answer = convert(n - 1);
    return answer;
}
