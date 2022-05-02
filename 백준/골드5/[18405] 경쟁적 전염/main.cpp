#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define BUFFER_SIZE 200
#define K_BUFFER_SIZE 1001
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
bool g_used[K_BUFFER_SIZE];
int N, K;
int S, X, Y;
using namespace std;

vector<int> initVi(void)
{
    int i, j;
    vector<int> vi;

    i = 0;
    while (i < N)
    {
        j = 0;
        while (j < N)
        {
            if (g_arr[i][j] && g_used[g_arr[i][j]] == false)
            {
                g_used[g_arr[i][j]] = true;
                vi.push_back(g_arr[i][j]);
            }
            j++;
        }
        i++;
    }
    sort(vi.begin(), vi.end());
    return (vi);
}

void bfs(vector<int> &vi)
{
    queue<tuple<int, int, int, int>> q;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0 ,0 ,1 ,-1};
    int i, j, k;
    int r, c, b, s;
    int dir;

    k = 0;
    while (k < vi.size())
    {
        i = 0;
        while (i < N)
        {
            j = 0;
            while (j < N)
            {
                if (g_arr[i][j] == vi[k])
                {
                    q.push(make_tuple(i, j, g_arr[i][j], 0));
                    g_visit[i][j] = true;
                }
                j++;
            }
            i++;
        }
        k++;
    }
    while (!q.empty())
    {
        r = get<0>(q.front());
        c = get<1>(q.front());
        b = get<2>(q.front());
        s = get<3>(q.front());
        q.pop();

        if (s == S + 1)
            break;
        if (g_arr[r][c] == 0)
            g_arr[r][c] = b;
        dir = 0;
        while (dir < 4)
        {
            int nr = r + dx[dir];
            int nc = c + dy[dir];

            if (nr >= 0 && nr <= N - 1 && nc >= 0 && nc <= N - 1)
            {
                if (g_arr[nr][nc] == 0 && g_visit[nr][nc] == false)
                {
                    q.push(make_tuple(nr, nc, b, s + 1));
                    g_visit[nr][nc] = true;
                }
            }
            dir++;
        }
    }
}

void solution(void)
{
    vector <int> vi;

    vi = initVi();
    bfs(vi);
    cout<<g_arr[X - 1][Y - 1]<<endl;
}

int main(void)
{
    int i, j;
    
    cin>>N>>K;
    i = 0;
    while (i < N)
    {
        j = 0;
        while (j < N)
        {
            cin>>g_arr[i][j];
            j++;
        }
        i++;
    }
    cin>>S>>X>>Y;
    solution();
    return (0);
}