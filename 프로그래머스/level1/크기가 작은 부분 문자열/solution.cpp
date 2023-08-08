#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    vector<unsigned long long> arr;
    for (int i = 0; i < t.length() - p.length() + 1; i++) {
        arr.push_back(stoull(t.substr(i, p.length())));
    }
    
    const unsigned long long target = stoull(p);
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= target)
            answer++;
    }
    return answer;
}
