#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int, int>> q;
    
    for (int i = 0; i < priorities.size(); i++)
    {
        if (i == location)
            q.push_back(make_pair(1, priorities[i]));
        else
            q.push_back(make_pair(0, priorities[i]));
    }
    while (q.size())
    {
        int toprint = q[0].second;
        int topidx = 0;
        for (int i = 1; i < q.size(); i++)
        {
            if (q[i].second > toprint)
            {
                toprint = q[i].second;
                topidx = i;
            }
        }
        if (toprint == q[0].second)
        {
            answer++;
            if (q[0].first)
                return (answer);
            q.erase(q.begin());
        }
        else
        {
            for (int i = 0; i < topidx; i++)
            {
                q.push_back(q[0]);
                q.erase(q.begin());
            }
        }
    }
    return (-1);
}