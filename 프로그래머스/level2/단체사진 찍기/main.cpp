#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>
using namespace std;

enum FRIENDS
{
    A = 1,
    C,
    F,
    J,
    M,
    N,
    R,
    T
};

#define BUFFER_SIZE 8
int g_order[BUFFER_SIZE];
bool g_used[BUFFER_SIZE + 1];
map<char, FRIENDS> m;

void initG();

int findIdx(int friends) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (g_order[i] == friends) {
            return (i);
        }
    }
    return (-1);
}

bool checkRule(vector<string> &data) {
    for (int i = 0; i < data.size(); i++) {
        int c1 = findIdx(m[data[i][0]]);
        int c2 = findIdx(m[data[i][2]]);
        int len = abs(c2 - c1);
        int pivot = data[i][4] - '0' + 1;
        
        switch (data[i][3]) {
            case '=':
                if (len != pivot)
                    return (false);
                break;
                
            case '>':
                if (len <= pivot)
                    return (false);
                break;
                
            case '<':
                if (len >= pivot)
                    return (false);
                break;
        }
    }
    return (true);
}

int dfs(int cur, vector<string> &data) {
    static int answer = 0;
    
    if (cur == 0) {
        answer = 0;
    }
    if (cur == BUFFER_SIZE) {
        if (checkRule(data)) {
            answer++;
        }
        return (answer);
    }
    for (int i = 1; i <= BUFFER_SIZE; i++) {
        if (!g_used[i]) {
            g_order[cur] = i;
            g_used[i] = true;
            dfs(cur + 1, data);
            g_order[cur] = 0;
            g_used[i] = false;
        }
    }
    return (answer);
}

int solution(int n, vector<string> data) {
    int answer = 0;
    
    initG();
    answer = dfs(0, data);
    return answer;
}

void initG() {
    for (int i = 0; i < BUFFER_SIZE; i++){
        g_order[i] = 0;
        g_used[i + 1] = false;
    }
    m.clear();
    m['A'] = FRIENDS::A;
    m['C'] = FRIENDS::C;
    m['F'] = FRIENDS::F;
    m['J'] = FRIENDS::J;
    m['M'] = FRIENDS::M;
    m['N'] = FRIENDS::N;
    m['R'] = FRIENDS::R;
    m['T'] = FRIENDS::T;
}
