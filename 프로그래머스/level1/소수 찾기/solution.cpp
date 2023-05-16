#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int n) {
    unordered_set<int> prime;
    unordered_set<int> visit;
    
    for (int i = 2; i <= n; i++) {
        if (visit.find(i) == visit.end()) {
            prime.insert(i);
            for (int j = 1; i * j <= n; j++) {
                visit.insert(i * j);
            }
        }
    }
    return prime.size();
}
