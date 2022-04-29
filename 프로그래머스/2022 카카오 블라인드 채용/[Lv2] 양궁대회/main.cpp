#include <string>
#include <vector>
#include <iostream>

using namespace std;

int isWin(vector<int> &info, vector<int> vi)
{
    int aScore = 0;
    int lScore = 0;
    int i;
    
    i = -1;
    while (++i < info.size())
    {
        if (info[i] == 0 && vi[i] == 0)
            continue;
        if (info[i] >= vi[i])
            aScore += 10 - i;
        else
            lScore += 10 - i;
    }
    if (lScore > aScore)
        return (lScore - aScore);
    else
        return (-1);
}

vector<int> dfs(int left, vector<int> &info, vector<int> vi, int depth)
{
    static int score;
    static vector<int> answer;
    vector<int> vt;
    int i, temp;
    
    if (depth == 11)
    {
        score = 0;
        answer = vi;
        answer[0] = -1;
    }
    if (left == 0)
    {
        temp = isWin(info, vi);
        if (temp != -1 && temp > score)
        {
            score = temp;
            answer = vi;
            return (answer);
        }
        vt.push_back(-1);
        return (vt);
    }
    i = depth - 1;
    if (i >= 0)
    {
        for (int j = left; j >= 0; j--)
        {
            vi[i] = j;
            dfs(left - j, info, vi, i);
        }
    }
    if (answer[0] != -1)
        return (answer);
    else
    {
        vt.push_back(-1);
        return (vt);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> vi(11, 0);
    
    answer = dfs(n, info, vi, 11);
    return answer;
}
