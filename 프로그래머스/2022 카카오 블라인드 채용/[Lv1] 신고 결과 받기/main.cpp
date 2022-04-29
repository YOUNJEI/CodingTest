#include <string>
#include <vector>
#define ID_LIST_BUFFER 1000
int g_arr[ID_LIST_BUFFER][ID_LIST_BUFFER];

using namespace std;

int findIdxUsingID(string s, vector<string> &id_list)
{
    int i;
    
    i = 0;
    while (i < id_list.size())
    {
        if (s.compare(id_list[i]) == 0)
            return (i);
        i++;
    }
    return (-1);
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    string reporter, reported;
    int i, j, m, temp;
    
    i = 0;
    while (i < report.size())
    {
        reporter = report[i].substr(0, report[i].find(" "));
        reported = report[i].substr(report[i].find(" ") + 1);
        g_arr[findIdxUsingID(reporter, id_list)][findIdxUsingID(reported, id_list)] = 1;
        i++;
    }
    i = 0;
    while (i < id_list.size())
    {
        int count = 0;
        j = 0;
        while (j < id_list.size())
        {
            if (g_arr[i][j])
            {
                m = 0;
                temp = 0;
                while (m < id_list.size())
                {
                    temp += g_arr[m][j];
                    m++;
                }
                if (temp >= k)
                    count++;
            }
            j++;
        }
        answer.push_back(count);
        i++;
    }
    return answer;
}
