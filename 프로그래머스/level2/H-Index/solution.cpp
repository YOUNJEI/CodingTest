#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int& i1, const int& i2) {
    return i1 > i2;
}

int solution(vector<int> c) {
    sort(c.begin(), c.end(), cmp);
    
    int i = 0;
    while (i < c.size() && i + 1 <= c[i])
        i++;
    return i;
}
