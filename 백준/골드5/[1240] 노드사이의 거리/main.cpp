#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

#define BUFFER_SIZE 1000
int g_dist[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE];
int N, M;

void visitReset(void)
{
	int i;

	i = 0;
	while (i < N)
	{
		g_visit[i] = false;
		i++;
	}
}

int min(int n1, int n2)
{
	if (n1 >= n2)
		return (n2);
	else
		return (n1);
}

int dfs(int from, int to, int dist)
{
	int answer = -1;
	int i, temp;

	g_visit[from] = true;
	if (g_dist[from][to])
		return (dist + g_dist[from][to]);
	i = 0;
	while (i < N)
	{
		if (g_dist[from][i] && g_visit[i] == false)
		{
			temp = dfs(i, to, dist + g_dist[from][i]);
			if (temp != -1)
			{
				if (answer == -1)
					answer = temp;
				else
					answer = min(answer, temp);
			}
		}
		i++;
	}
	if (answer != -1)
		return (answer);
	else
		return (-1);
}
int main(void)
{
	int i;
	int r, c, d;
	vector<pair<int, int>> vi;
	
	cin>>N>>M;
	i = 0;
	while (i < N - 1)
	{
		cin>>r>>c>>d;
		g_dist[r - 1][c - 1] = d;
		g_dist[c - 1][r - 1] = d;
		i++;
	}
	i = 0;
	while (i < M)
	{
		cin>>r>>c;
		vi.push_back(make_pair(r, c));
		i++;
	}
	i = 0;
	while (i < vi.size())
	{
		visitReset();
		r = vi[i].first;
		c = vi[i].second;
		cout<<dfs(r - 1, c - 1, 0)<<endl;
		i++;
	}
}
