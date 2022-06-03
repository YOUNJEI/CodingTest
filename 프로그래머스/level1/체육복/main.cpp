#include <string>
#include <vector>
#define BUFFER_SIZE 30
int g_arr[BUFFER_SIZE + 1];
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for (int i = 1; i <= n; i++)
        g_arr[i] = 1;
    for (int i = 0; i < reserve.size(); i++)
        g_arr[reserve[i]]++;
    for (int i = 0; i < lost.size(); i++)
        g_arr[lost[i]]--;
    
    for (int i = 1; i <= n; i++)
    {
        if (g_arr[i] == 0)
        {
            if (i - 1 >= 0 && g_arr[i - 1] > 1)
            {
                g_arr[i - 1]--;
                continue ;
            }
            if (i + 1 <= n && g_arr[i + 1] > 1)
            {
                g_arr[i + 1]--;
                continue ;
            }
            answer++;
        }
    }
    return (n - answer);
}
