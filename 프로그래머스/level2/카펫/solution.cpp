#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int r = 1; r <= yellow; r++) {
        if (yellow % r != 0)
            continue;
        int c = yellow / r;
        
        int rect = (c + 2) * (r + 2);
        if (rect - yellow == brown) {
            answer.push_back(c + 2);
            answer.push_back(r + 2);
            return answer;
        }
    }
    return answer;
}
