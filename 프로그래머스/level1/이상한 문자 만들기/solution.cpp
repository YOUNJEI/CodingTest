#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int i = 0;
    while (s[i] == ' ') {
        answer += s[i];
        i++;
    }
    while (i < s.length()) {
        if (s[i] == ' ') {
            answer += s[i];
            i++;
            continue;
        }
        int j = 0;
        while (i + j < s.length() && s[i + j] != ' ') {
            if (j % 2 == 0)
                answer += toupper(s[i + j]);
            else
                answer += tolower(s[i + j]);
            j++;
        }
        i += j;
    }
    return answer;
}
