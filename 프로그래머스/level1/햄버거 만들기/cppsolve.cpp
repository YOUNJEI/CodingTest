#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
    const static int order[] = {1, 3, 2, 1};
    
    int answer = 0;
    stack<int> s;
    stack<int> restore;
    
    int i = 0;
    while (i < ingredient.size()) {
        s.push(ingredient[i]);
        
        if (!s.empty()) {
            if (s.top() == 1 && s.size() >= 4) {
                int j = 0;
                while (j < 4 && s.top() == order[j]) {
                    int temp = s.top();
                    s.pop();
                    restore.push(temp);
                    j++;
                }
                if (j == 4) {
                    answer++;
                    while (!restore.empty())
                        restore.pop();
                }
                else {
                    while (!restore.empty()) {
                        int temp = restore.top();
                        restore.pop();
                        s.push(temp);
                    }
                }
            }
        }
        i++;
    }
    return answer;
}
