#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const char& c1, const char& c2) {
    return c1 > c2;
}

long long solution(long long n) {
    long long answer = 0;
    string sn = to_string(n);
    vector<int> arr;
    
    for (int i = 0; i < sn.length(); i++)
        arr.push_back(sn[i] - '0');
    sort(arr.begin(), arr.end(), cmp);
    string sans = "";
    for (int i = 0; i < arr.size(); i++)
        sans += arr[i] + '0';
    return stoll(sans);
}
