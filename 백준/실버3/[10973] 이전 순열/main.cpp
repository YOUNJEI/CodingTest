#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define BUFFER_SIZE 10001
bool g_visit[BUFFER_SIZE];
vector<int> vi;
vector<int> answer;
int N;

void makeLeft(void)
{
	for (int i = answer.size(); i < N; i++)
	{
		for (int j = N; j >= 1; j--)
		{
			if (!g_visit[j])
			{
				answer.push_back(j);
				g_visit[j] = true;
				break;
			}
		}
	}
}

void dfs(int idx)
{
	if (idx - 1 >= 0 && vi[idx - 1] < vi[idx])
		dfs(idx - 1);
	else if (idx - 1 >= 0)
	{
		for (int i = 0; i < idx - 1; i++)
		{
			g_visit[vi[i]] = true;
			answer.push_back(vi[i]);
		}
		makeLeft();
	}
}

void solution(void)
{
	dfs(vi.size() - 1);
	if (answer.size() == 0)
		cout<<"-1";
	else
	{
		for (int i = 0; i < answer.size(); i++)
			cout<<answer[i]<<" ";
	}
}

int main(void)
{
	int temp;

	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin>>temp;
		vi.push_back(temp);
	}
	solution();
	return (0);
}
