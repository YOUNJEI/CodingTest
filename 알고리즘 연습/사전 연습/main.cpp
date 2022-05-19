#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
	return a.second < b.second;
}

bool cmp2(pair<string, int> &a, pair<string, int> &b)
{
	return a.second > b.second;
}

int main(void)
{
	map<string, int> m1;
	
	m1["고윤제"] = 10;
	m1["고윤제2"] = 90;
	m1["ABC"] = 50;
	m1["ABC2"] = 100;
	m1["이승주"] = 10;
	m1["이승주2"] = 30;
	cout<<"map 출력"<<endl;
	for (auto iter : m1)
		cout<<iter.first<<" :"<<iter.second<<endl;
	vector<pair<string, int>> v(m1.begin(), m1.end());
	cout<<"정렬 전"<<endl;
	for (int i = 0; i < v.size(); i++)
		cout<<v[i].first<<" :"<<v[i].second<<endl;

	sort(v.begin(), v.end(), cmp2);
	cout<<"정렬 후"<<endl;
	for (int i = 0; i < v.size(); i++)
		cout<<v[i].first<<" :"<<v[i].second<<endl;
	return (0);
}
