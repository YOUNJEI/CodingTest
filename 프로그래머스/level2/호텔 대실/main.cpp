#include <string>
#include <vector>
#include <iostream>
#define BUFFER_SIZE 1440
int g_room[BUFFER_SIZE];
using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for (int i = 0; i < book_time.size(); i++) {
        int st = stoi(book_time[i][0].substr(0, 2));
        int sm = stoi(book_time[i][0].substr(3, 2));
        int et = stoi(book_time[i][1].substr(0, 2));
        int em = stoi(book_time[i][1].substr(3, 2));
        
        int s = st * 60 + sm;
        int e = et * 60 + em;
        
        for (int j = s; j < BUFFER_SIZE && j <= e + 9; j++) {
            g_room[j]++;
        }
    }
    for (int i = 0; i < BUFFER_SIZE; i++)
        answer = max(answer, g_room[i]);
    return answer;
}
