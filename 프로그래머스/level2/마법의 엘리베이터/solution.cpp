#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int recur(const int storey) {
    if (storey < 10) {
        if (storey < 6)
            return storey;
        else
            return (10 - storey) + 1;
    }
    
    int l = log10(storey);
    int top = abs(storey - pow(10, l + 1));
    int bottom = storey - pow(10, l);
    
    if (top < bottom)
        return 1 + recur(top);
    else
        return 1 + recur(bottom);
}

int solution(int storey) {
    int answer = 0;
    
    answer = recur(storey);
    return answer;
}
