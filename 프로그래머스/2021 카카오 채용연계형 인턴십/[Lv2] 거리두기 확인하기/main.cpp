#include <string>
#include <vector>
#define WAITING_ROOM_SIZE 5
using namespace std;

bool g_visit[WAITING_ROOM_SIZE][WAITING_ROOM_SIZE];

int max(int n1, int n2)
{
    if (n1 >= n2)
        return (n1);
    else
        return (n2);
}

int myAbs(int n)
{
    if (n >= 0)
        return (n);
    else
        return (-n);
}

int myDist(int r1, int c1, int r2, int c2)
{
    return (myAbs(r1 - r2) + myAbs(c1 - c2));
}

bool isItVaildPos(int r, int c, vector<string>& place)
{
    int i, j;
    
    i = r;
    while (i < place.size())
    {
        if (i == r)
            j = c + 1;
        else
            j = 0;
        while (j < place[i].length())
        {
            if (place[i][j] == 'P')
            {
                if (myDist(r, c, i, j) == 1)
                    return (false);
                if (myDist(r, c, i, j) == 2)
                {
                    if (r != i && c != j)
                    {
                        if (place[i - 1][j] != 'X' || place[i][c] != 'X')
                            return (false);
                    }
                    if (r == i)
                    {
                        if (place[i][j - 1] != 'X')
                            return (false);
                    }
                    if (c == j)
                    {
                        if (place[i - 1][j] != 'X')
                            return (false);
                    }
                }
            }
            j++;
        }
        i++;
    }
    return (true);
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < places.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < places[i].size(); j++)
        {
            for (int k = 0; k < places[i][j].length(); k++)
            {
                if (places[i][j][k] == 'P')
                {
                    if (!isItVaildPos(j, k, places[i]))
                        flag = false;
                }
            }
        }
        if (flag)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}
