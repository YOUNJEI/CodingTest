#include <iostream>
#include <vector>
using namespace std;
#define BUFFER_SIZE 500
vector<int> vi;
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
int H, W;


void fillOutWater(int r, int c)
{
	bool flag = false;

	for (int i = c + 1; i < W; i++)
	{
		if (g_arr[r][i] == 1)
		{
			flag = true;
			break ;
		}
		else if (g_arr[r][i] == 2)
			break ;
	}
	if (flag)
	{
		for (int i = c + 1; i < W; i++)
			if (g_arr[r][i] == 0)
				g_arr[r][i] = 2;
			else
				break ;
	}
	flag = false;
	for (int i = c - 1; i >= 0; i--)
	{
		if (g_arr[r][i] == 1)
		{
			flag = true;
			break ;
		}
		else if (g_arr[r][i] == 2)
			break ;
	}
	if (flag)
	{
		for (int i = c - 1; i >= 0; i--)
		{
			if (g_arr[r][i] == 0)
				g_arr[r][i] = 2;
			else
				break ;
		}
	}
}

int countWater(void)
{
	int count = 0;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (g_arr[i][j] == 2)
				count++;
		}
	}
	return (count);
}

void solve(void)
{
	int answer = 0;
	int vSize = vi.size();

	for (int i = 0; i < vSize; i++)
	{
		for (int j = H - 1; j >= H - vi[i]; j--)
		{
			fillOutWater(j, i);
		}
	}
	answer = countWater();
	cout<<answer;
}

int main(void)
{
	int temp;

	cin >> H >> W;
	for (int i = 0; i < W; i++)
	{
		cin>>temp;
		vi.push_back(temp);
		for (int j = H - 1; j >= H - temp; j--)
		{
			g_arr[j][i] = 1;
		}
	}
	solve();
	return (0);
}
