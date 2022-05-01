#include <iostream>
#include <queue>
#include <utility>
#define BUFFER_SIZE 100

using namespace std;

int W, H;
int g_arr[BUFFER_SIZE + 2][BUFFER_SIZE + 2];

int bfs()
{
	int length = 0;
	int r, c, dir;
	int mv[2][6][2] = {
		{{1,-1}, {1,0}, {-1,-1}, {-1,0}, {0,-1}, {0,1}},
		{{1,0}, {1,1}, {-1,0}, {-1,1}, {0,-1}, {0,1}}
	};
	queue <pair<int, int>> q;

	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		r = q.front().first;
		c = q.front().second;
		q.pop();

		dir = 0;
		while (dir < 6)
		{
			int line = r % 2;
			int nr = r + mv[line][dir][0];
			int nc = c + mv[line][dir][1];
			if (nr >= 0 && nr <= H + 1 && nc >= 0 && nc <= W + 1)
			{
				if (g_arr[nr][nc] == 0)
				{
					q.push(make_pair(nr, nc));
					g_arr[nr][nc] = -1;
				}
				else if (g_arr[nr][nc] == 1)
					length++;
			}
			dir++;
		}
	}
	return (length);
}

void solution(void)
{
	int answer = 0;
	//fill_inside();
	//reset_visit();
	answer = bfs();
	cout<<answer<<endl;
}

int main(void)
{
	int i, j;
	cin>>W>>H;
	i = 1;
	while (i <= H)
	{
		j = 1;
		while (j <= W)
		{
			cin>>g_arr[i][j];
			j++;
		}
		i++;
	}
	solution();
	return (0);
}
