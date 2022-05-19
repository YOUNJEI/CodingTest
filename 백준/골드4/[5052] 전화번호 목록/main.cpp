#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t;
vector<vector<string>> vs;

bool check(vector<string> &v)
{
	int i, j;
	int vSize = v.size();
	bool flag;

	for (i = 0; i < vSize - 1; i++)
	{
		flag = true;
		for (j = 0; j < v[i].length(); j++)
		{
			if (v[i][j] != v[i + 1][j])
			{
				flag = false;
				break ;
			}
		}
		if (flag && j == v[i].length())
			return (false);
	}
	return (true);
}

int main(void)
{
	int n;
	string input;
	vector<string> temp;

	cin>>t;
	for (int i = 0; i < t; i++)
	{
		cin>>n;
		temp.clear();
		for (int j = 0; j < n; j++)
		{
			cin>>input;
			temp.push_back(input);
		}
		vs.push_back(temp);
	}
	for (int i = 0; i < t; i++)
		sort(vs[i].begin(), vs[i].end());
	for (int i = 0; i < t; i++)
	{
		if (check(vs[i]))
			cout<<"YES"<<"\n";
		else
			cout<<"NO"<<"\n";
	}
	return (0);
}
