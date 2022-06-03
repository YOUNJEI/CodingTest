#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int makeanswer(vector<int> &array, vector<int> &commands)
{
    vector<int> temp;
    int from = min(commands[0], commands[1]);
    int to = max(commands[0], commands[1]);
    
    for (int i = from - 1; i < to; i++)
    {
        temp.push_back(array[i]);
    }
    sort(temp.begin(), temp.end());
    return (temp[commands[2] - 1]);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++)
        answer.push_back(makeanswer(array, commands[i]));
    return answer;
}
