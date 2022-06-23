#include <vector>
#include <iostream>

using namespace std;
bool g_used [10];

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int lastNum = 0;
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (lastNum != arr[i])
            g_used[lastNum] = false;
        if (!g_used[arr[i]])
        {
            g_used[arr[i]] = true;
            answer.push_back(arr[i]);
            lastNum = arr[i];
        }
    }
    return (answer);
}
