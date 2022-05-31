#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define BUFFER_SIZE 11
#define MIN_BOUND -1000000001
#define MAX_BOUND 1000000001
int g_arr[BUFFER_SIZE];
bool g_visit[BUFFER_SIZE];
int N;
int g_min_num = MAX_BOUND;
int g_max_num = MIN_BOUND;
int g_plus, g_minus, g_divide, g_mul;

void dfs(int p, int m, int d, int mu, int K, int oc)
{
    if (oc == N - 1)
    {
        g_max_num = max(g_max_num, K);
        g_min_num = min(g_min_num, K);
        return ;
    }
    if (p < g_plus)
        dfs(p + 1, m, d, mu, K + g_arr[oc + 1], oc + 1);

    if (m < g_minus)
        dfs(p, m + 1, d, mu, K - g_arr[oc + 1], oc + 1);
                
    if (d < g_divide)
        dfs(p, m, d + 1, mu, K / g_arr[oc + 1], oc + 1);

    if (mu < g_mul)
        dfs(p, m, d, mu + 1, K * g_arr[oc + 1], oc + 1);
}

void solution(void)
{
    dfs(0, 0, 0, 0, g_arr[0], 0);
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> g_arr[i];
    cin >> g_plus >> g_minus >> g_mul >> g_divide;
    solution();
    cout<<g_max_num<<'\n';
    cout<<g_min_num<<'\n';
    return (0);
}