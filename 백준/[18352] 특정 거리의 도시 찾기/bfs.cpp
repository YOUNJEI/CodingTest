#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define BUFFER_SIZE 300000
vector<int> g_edges[BUFFER_SIZE + 1];
bool g_visit[BUFFER_SIZE + 1];
int N, M, K, X;

vector<int> bfs(void)
{
	vector<int> answer;
	queue<pair<int, int>> q;
	q.push(make_pair(X, 0));	// V, dist
	g_visit[X] = true;
	
	while (!q.empty())
	{
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (dist == K)
			answer.push_back(now);
		for (int i = 0; i < g_edges[now].size(); i++)
		{
			int to = g_edges[now][i];
			
			if (!g_visit[to])
			{
				q.push(make_pair(to, dist + 1));
				g_visit[to] = true;
			}
		}
	}
	return (answer);
}

vector<int> solution(void)
{
	vector<int> answer;

	answer = bfs();
	sort(answer.begin(), answer.end());
	return (answer);
}

int main(void)
{
	int input[2];
	vector<int> answer;

	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++)
	{
		cin >> input[0] >> input[1];
		g_edges[input[0]].push_back(input[1]);
	}
	answer = solution();
	if (answer.size() == 0)
		cout << "-1\n";
	else
	{
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << '\n';
		}
	}
	return (0);
}
