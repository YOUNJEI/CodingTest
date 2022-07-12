#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <utility>
#include <iostream>
using namespace std;

vector<string> split(string str, char delimiter);

map<string, string> m;                  // uid, nickname
vector<pair<string, string>> subAnswer; // uid, condition

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for (int i = 0; i < record.size(); i++) {
        vector<string> spl = split(record[i], ' ');
        
        if (!spl[0].compare("Enter")) {
            m[spl[1]] = spl[2];
            subAnswer.push_back(make_pair(spl[1], spl[0]));
        }
        else if (!spl[0].compare("Leave")) {
            subAnswer.push_back(make_pair(spl[1], spl[0]));
        }
        else {
            m[spl[1]] = spl[2];
        }
    }
    for (int i = 0; i < subAnswer.size(); i++) {
        string temp = "";
        temp += m[subAnswer[i].first];
        
        if (!subAnswer[i].second.compare("Enter")) {
            temp += "님이 들어왔습니다.";
        }
        else {
            temp += "님이 나갔습니다.";
        }
        answer.push_back(temp);
    }
    return answer;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}
