#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    
    for (int i = 0; i < cards.size(); i++) {
        unordered_set<int> s1;
        s1.insert(i + 1);
        
        int s = cards[i];
        while (s1.find(s) == s1.end()) {
            s1.insert(s);
            s = cards[s - 1];
        }
        if (s1.size() == cards.size())
            continue;
        for (int j = 0; j < cards.size(); j++) {
            if (s1.find(j + 1) != s1.end())
                continue;
            unordered_set<int> s2;
            s2.insert(j + 1);
            
            int e = cards[j];
            while (s2.find(e) == s2.end() && s1.find(e) == s1.end()) {
                s2.insert(e);
                e = cards[e - 1];
            }
            answer = max(answer, (int)s1.size() * (int)s2.size());
        }
    }
    return answer;
}
