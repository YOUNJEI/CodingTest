#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.length(); i++) {
        int cur = s[i];
        if (cur >= 'A' && cur <= 'Z') {
            cur += n;
            while (cur > 'Z')
                cur -= 26;
        } else if (cur >= 'a' && cur <= 'z') {
            cur += n;
            while (cur > 'z') {
                cur -= 26;
            }
        }
        answer += cur;
    }
    return answer;
}
