#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> m;
    set<int> s;
    
    for (int i = 0; i < topping.size(); i++)
        m[topping[i]]++;
    for (int i = 0; i < topping.size(); i++) {
        s.insert(topping[i]);
        auto it = m.find(topping[i]);
        it->second--;
        if (it->second == 0)
            m.erase(it);
        if (s.size() == m.size())
            answer++;
    }
    
    return answer;
}
