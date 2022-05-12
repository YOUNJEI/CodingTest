#include <iostream>
#include <vector>
#include <utility>
using namespace std;

string g_arr[4];
int g_cur[4];
int K;
vector<pair<int, int>> vp;

void moveCounterClock(int idx, int loop)
{
	g_cur[idx] += loop;
	if (g_cur[idx] > 7)
	{
		while (g_cur[idx] > 7)
		{
			g_cur[idx] = g_cur[idx] - 8;
		}
	}
}

void moveClock(int idx, int loop)
{
	g_cur[idx] -= loop;
	if (g_cur[idx] < 0)
	{
		while (g_cur[idx] < 0)
		{
			g_cur[idx] = 8 + g_cur[idx];
		}
	}
}

int getLeftIdx(int idx)
{
	if (g_cur[idx] - 2 < 0)
		return (6 + g_cur[idx]);
	return (g_cur[idx] - 2);
}

int getRightIdx(int idx)
{
	if (g_cur[idx] + 2 > 7)
		return (g_cur[idx] - 6);
	return (g_cur[idx] + 2);
}

void rotate(int idx, int dir)
{
	if (idx - 1 >= 0 && g_arr[idx - 1][getRightIdx(idx - 1)] != g_arr[idx][getLeftIdx(idx)])
	{
		if (idx - 2 >= 0 && g_arr[idx - 2][getRightIdx(idx - 2)] != g_arr[idx - 1][getLeftIdx(idx - 1)])
		{
			if (idx - 3 >= 0 && g_arr[idx - 3][getRightIdx(idx - 3)] != g_arr[idx - 2][getLeftIdx(idx - 2)])
			{
				if (dir == 1)
					moveCounterClock(idx - 3, 1);
				else
					moveClock(idx - 3, 1);
			}
			if (dir == 1)
				moveClock(idx - 2, 1);
			else
				moveCounterClock(idx - 2, 1);
		}
		if (dir == 1)
			moveCounterClock(idx - 1, 1);
		else
			moveClock(idx - 1, 1);
	}
	if (idx + 1 < 4 && g_arr[idx][getRightIdx(idx)] != g_arr[idx + 1][getLeftIdx(idx + 1)])
	{
		if (idx + 2 < 4 && g_arr[idx + 1][getRightIdx(idx + 1)] != g_arr[idx + 2][getLeftIdx(idx + 2)])
		{
			if (idx + 3 < 4 && g_arr[idx + 2][getRightIdx(idx + 2)] != g_arr[idx + 3][getLeftIdx(idx + 3)])
			{
				if (dir == 1)
					moveCounterClock(idx + 3, 1);
				else
					moveClock(idx + 3, 1);
			}
			if (dir == 1)
				moveClock(idx + 2, 1);
			else
				moveCounterClock(idx + 2, 1);
		}
		if (dir == 1)
			moveCounterClock(idx + 1, 1);
		else
			moveClock(idx + 1, 1);
	}
	if (dir == 1)
		moveClock(idx, 1);
	else
		moveCounterClock(idx, 1);
}

int solution(void)
{
	int idx, dir;
	int score = 0;
	int tok;

	for (int i = 0; i < K; i++)
	{
		idx = vp[i].first;
		dir = vp[i].second;
		rotate(idx, dir);
	}
	tok = 1;
	for (int i = 0; i < 4; i++)
	{
		if (g_arr[i][g_cur[i]] == '1')
		{
			score += tok;
		}
		tok = tok << 1;
	}
	return (score);
}

int main(void)
{
	int idx, dir;
	int temp;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &temp);
			g_arr[i][j] = temp + '0';
		}
	}
	cin>>K;
	for (int i = 0; i < K; i++)
	{
		cin>>idx>>dir;
		vp.push_back(make_pair(idx - 1, dir));
	}
	cout<<solution();
	return (0);
}
