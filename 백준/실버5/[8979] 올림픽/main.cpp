#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

bool compare(vector<int> &info1, vector<int> &info2)
{
	if (info1[1] == info2[1])
	{
		if (info1[2] == info2[2])
		{
			if (info1[3] == info2[3])
			{
				info1[4] = 1;
				info2[4] = 1;
				return (false);
			}
			else
				return (info1[3] > info2[3]);
		}
		else
			return (info1[2] > info2[2]);
	}
	else
		return (info1[1] > info2[1]);
}

int solution(vector<vector<int>> &info)
{
	sort(info.begin(), info.end(), compare);
	int size = info.size();
	int i;
	int rank = 1;

	i = 0;
	while (i < size)
	{
		if (info[i][4])
		{
			int j = i;
			int c = 0;
			while (j < size)
			{
				info[j].push_back(rank);
				c++;
				j++;
				if (j >= size)
					break ;
				if (info[j][1] != info[j - 1][1] || info[j][2] != info[j - 1][2] || info[j][3] != info[j - 1][3])
					break ;
			}
			rank += c;
			i = j;
		}
		else
		{
			info[i].push_back(rank);
			i++;
			rank++;
		}
	}
	i = 0;
	while (i < size)
	{
		if (info[i][0] == K)
			return (info[i][5]);
		i++;
	}
	return (-1);
}

int main(void)
{
	vector<vector<int>> info;
	vector<int> temp;
	int inputInfo[4];

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		temp.clear();
		for (int j = 0; j < 4; j++)
		{
			cin >> inputInfo[j];
			temp.push_back(inputInfo[j]);
		}
		temp.push_back(0);
		info.push_back(temp);
	}
	cout<<solution(info)<<'\n';
	return (0);
}
