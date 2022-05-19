#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
	map<string, int> m;
	vector<pair<string, double>> vd;
	string s;
	int N = 0;
	
	while (getline(cin, s))
	{
		if (m.find(s) == m.end())
			m[s] = 1;
		else
			m[s]++;
		N++;
	}
	for (auto iter=m.begin(); iter != m.end(); iter++)
		vd.push_back(make_pair(iter->first, (double)iter->second/N));
	sort(vd.begin(), vd.end());
	cout<<fixed;
	cout.precision(4);
	for (int i = 0; i < vd.size(); i++)
		cout<<vd[i].first<<" "<<round(vd[i].second * 100 * 10000)/10000<<endl;
}
