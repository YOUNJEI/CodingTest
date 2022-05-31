#include <iostream>
#include <vector>
using namespace std;

vector<string> vs;
long long T;

bool check(string s)
{
	int i, size;
	int bracket;

	i = 0;
	size = s.length();
	bracket = 0;
	while (i < size)
	{
		if (s[i] == '(')
			bracket++;
		else if (s[i] == ')')
			bracket--;

		if (bracket < 0)
			return (false);
		i++;
	}
	if (bracket)
		return (false);
	return (true);
}

vector<string> solution(void)
{
	vector<string> temp;

	for (long long i = 0; i < T; i++)
	{
		if (check(vs[i]))
			temp.push_back("YES");
		else
			temp.push_back("NO");
	}
	return (temp);
}

int main(void)
{
	cin >> T;
	for (long long i = 0; i < T; i++)
	{
		string temp;
		cin >> temp;
		vs.push_back(temp);
	}
	vector<string> answer = solution();
	for (long long i = 0; i < T; i++)
		cout << answer[i] << '\n';
	return (0);
}
