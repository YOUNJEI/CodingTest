#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string, int> m1;
    map<int, string> m2;
    for (int i = 0 ; i < players.size(); i++) {
        m1[players[i]] = i + 1;
        m2[i + 1] = players[i];
    }
    for (int i = 0; i < callings.size(); i++) {
        int curRank = m1[callings[i]];
        string frontName = m2[curRank - 1];
        m1[callings[i]] = curRank - 1;
        m1[frontName] = curRank;
        m2[curRank - 1] = callings[i];
        m2[curRank] = frontName;
    }
    for (int i = 0; i < players.size(); i++)
        answer.push_back(m2[i + 1]);
    return answer;
}
