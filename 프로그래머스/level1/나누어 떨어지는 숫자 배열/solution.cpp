#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    set<int> s;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % divisor == 0)
            s.insert(arr[i]);
    }
    if (s.empty())
        return vector<int>({-1});
    return vector<int>(s.begin(), s.end());
}
