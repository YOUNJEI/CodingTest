#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M;
#define BUFFER_SIZE 8
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
int g_arr2[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
queue<pair<int, int>> q;

int max(int n1, int n2)
{
    if (n1 >= n2)
        return (n1);
    else
        return (n2);
}

void reset_arr(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			g_arr2[i][j] = g_arr[i][j];
		}
	}
}

void reset_visit(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            g_visit[i][j] = false;
        }
    }
}

int count_safe_area(void)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (g_arr2[i][j] == 0)
                count++;
        }
    }
    return (count);
}

int bfs(void)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        g_arr2[x][y] = 2;
        
        if (x < N - 1 && g_arr2[x + 1][y] == 0 && g_visit[x + 1][y] == false)
        {
            q.push(make_pair(x + 1, y));
            g_visit[x + 1][y] = true;
        }
        if (x > 0 && g_arr2[x - 1][y] == 0 && g_visit[x - 1][y] == false)
        {
            q.push(make_pair(x - 1, y));
            g_visit[x - 1][y] = true;
        }
        if (y < M - 1 && g_arr2[x][y + 1] == 0 && g_visit[x][y + 1] == false)
        {
            q.push(make_pair(x, y + 1));
            g_visit[x][y + 1] = true;
        }
        if (y > 0 && g_arr2[x][y - 1] == 0 && g_visit[x][y - 1] == false)
        {
            q.push(make_pair(x, y - 1));
            g_visit[x][y - 1] = true;
        }
    }
    return (count_safe_area());
}

int comb(int r, int c, int count)
{
    static int safe_area = 0;
    if (count == 3)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (g_arr[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                    g_visit[i][j] = true;
                }
            }
        }
        reset_arr();
        safe_area = max(safe_area, bfs());
        reset_visit();
    }
    else
    {
        for (int i = r; i < N; i++)
        {
		int j;

		if (i == r)
			j = c + 1;
		else
			j = 0;
		while (j < M)
		{
			if (g_arr[i][j] == 0)
			{
				g_arr[i][j] = 1;
				comb(i, j, count + 1);
				g_arr[i][j] = 0;
			}
			j++;
		}
        }
    }
    return (safe_area);
}

void solve(void)
{
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (g_arr[i][j] == 0)
            {
                g_arr[i][j] = 1;
                answer = max(answer, comb(i, j, 1));
                g_arr[i][j] = 0;
            }
        }
    }
    cout<<answer;
}

int main(void)
{
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin>>g_arr[i][j];
        }
    }
    solve();
}
