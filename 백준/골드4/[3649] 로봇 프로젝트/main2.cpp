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

pair<int, int> solution(void)
{
	while (g_answerRight > g_answerLeft)
	{
		if (vi[g_answerLeft] + vi[g_answerRight] == x)
			return (make_pair(vi[g_answerLeft], vi[g_answerRight]));
		else if (vi[g_answerLeft] + vi[g_answerRight] > x)
			g_answerRight--;
		else
			g_answerLeft++;
	}
	return (make_pair(-1, -1));
}

int main(void)
{
	vector<pair<int, int>> answer;
	string s;

	while(1)
	{
		cin>>x>>n;
		if (cin.eof())
			break;
		x *= NANO;

		int temp;
		vi.clear();
		for (int i = 0; i < n; i++)
		{
			cin>>temp;
			vi.push_back(temp);
		}
		cin.ignore();
		sort(vi.begin(), vi.end());
		g_answerLeft = 0;
		g_answerRight = vi.size() - 1;
		pair<int, int> p = solution();
		if (p.first != -1)
			cout<<"yes "<<p.first<<" "<<p.second<<'\n';
		else
			cout<<"danger\n";
	}
	return (0);
}
