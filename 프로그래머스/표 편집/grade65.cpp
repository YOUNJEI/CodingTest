#include <string>
#include <vector>
#include <stack>
#include <sstream>
#define BUFFER_SIZE 1000000
using namespace std;

bool g_used[BUFFER_SIZE];
int g_curIdx;
int g_maxBound;
stack<int> g_stack;

void initUsed(int n)
{
    int i;
    
    i = 0;
    while (i < n)
    {
        g_used[i] = true;
        i++;
    }
}

void cmd_UX(int X)
{
    int i;
    
    i = 0;
    while (i < X)
    {
        if (g_used[g_curIdx - 1])
            i++;
        g_curIdx--;
    }
}

void cmd_DX(int X)
{
    int i;
    
    i = 0;
    while (i < X)
    {
        if (g_used[g_curIdx + 1])
            i++;
        g_curIdx++;
    }
}

void cmd_C(void)
{
    g_stack.push(g_curIdx);
    g_used[g_curIdx] = false;
    if (g_curIdx < g_maxBound - 1)
        cmd_DX(1);
    else
    {
        g_maxBound = g_curIdx;
        cmd_UX(1);
    }
}

void cmd_Z(void)
{
    g_used[g_stack.top()] = true;
    if (g_stack.top() == g_maxBound)
        g_maxBound++;
    g_stack.pop();
}

vector<string> split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<string> temp;
    int i, cmd_num;
    
    initUsed(n);
    g_curIdx = k;
    g_maxBound = n;
    
    i = 0;
    while (i < cmd.size())
    {
        switch (cmd[i][0])
        {
            case 'U':
                temp = split(cmd[i], ' ');
                cmd_num = stoi(temp[1]);
                //temp.clear();
                cmd_UX(cmd_num);
                break;
                
            case 'D':
                temp = split(cmd[i], ' ');
                cmd_num = stoi(temp[1]);
                //temp.clear();
                cmd_DX(cmd_num);
                break;
                
            case 'C':
                cmd_C();
                break;
                
            case 'Z':
                cmd_Z();
                break;
        }
        i++;
    }
    i = 0;
    while (i < n)
    {
        if (g_used[i])
            answer += "O";
        else
            answer += "X";
        i++;
    }
    return answer;
}
