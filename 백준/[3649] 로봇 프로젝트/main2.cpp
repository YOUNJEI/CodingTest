#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define NANO 10000000
int x;
int n;
vector<int> vi;
int g_answerLeft = 0;
int g_answerRight = 0;

int diffabs(int n1, int n2)
{
	if (n1 - n2 >= 0)
		return (n1 - n2);
	else
		return (-(n1 - n2));
}

bool binarySearch(int start, int cur, int size)
{
	while (start < cur && cur <= size)
	{
		if (vi[start] + vi[cur] == x * NANO)
		{
			g_answerLeft = start;
			g_answerRight = cur;
			return (true);
		}
		else if (vi[start] + vi[cur] > x * NANO)
		{
			size = cur;
			cur = ((start + cur) / 2) + 1;
		}
		else
		{
			cur = ((cur + size) / 2) + 1;
		}
	}
	return (false);
}

pair<int, int> solution(void)
{
	int temp;

	for (int i = 0; i < vi.size(); i++)
	{
		temp = binarySearch(i, vi.size() - 1, vi.size() - 1);
		if (temp)
			return (make_pair(vi[g_answerLeft], vi[g_answerRight]));
	}
	return (make_pair(-1, -1));
}

int main(void)
{
	int count = 0;
	vector<pair<int, int>> answer;
	string s;

	while (getline(cin, s))
	{
		x = s[0] - '0';
		cin>>n;

		int temp;
		vi.clear();
		for (int i = 0; i < n; i++)
		{
			cin>>temp;
			vi.push_back(temp);
		}
		cin.ignore();
		sort(vi.begin(), vi.end());
		answer.push_back(solution());
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		if(answer[i].first != -1)
			cout<<"yes "<<answer[i].first<<" "<<answer[i].second<<'\n';
		else
			cout<<"danger\n";
	}
	return (0);
}
