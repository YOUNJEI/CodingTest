#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

vector<string> vs;
int N;

bool compare(const string &s1, const string &s2)
{
	if (s1.length() == s2.length())
		return (s1.compare(s2) < 0);
	return (s1.length() < s2.length());
}

void solution(void)
{
	sort(vs.begin(), vs.end(), compare);
}

int main(void)
{
	set<string> s;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;

		cin >> temp;
		s.insert(temp);
	}
	for (std::set<string>::iterator it = s.begin(); it != s.end(); it++)
		vs.push_back(*it);
	solution();
	for (int i = 0; i < vs.size(); i++)
		cout << vs[i] << '\n';
	return (0);
}
