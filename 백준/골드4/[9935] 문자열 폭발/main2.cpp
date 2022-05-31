#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

string solution(const string ori, const string exp)
{
	string answer = "";
	stack<pair<char, int>> s;
	int i, size;

	i = 0;
	size = ori.length();
	while (i < size)
	{
		if (s.empty())
		{
			if (ori[i] == exp[0])
				s.push(make_pair(ori[i], 1));
			else
				s.push(make_pair(ori[i], 0));
		}
		else if (ori[i] == exp[s.top().second])
			s.push(make_pair(ori[i], s.top().second + 1));
		else
		{
			if (ori[i] == exp[0])
				s.push(make_pair(ori[i], 1));
			else
				s.push(make_pair(ori[i], 0));
		}
		if (s.top().second == exp.length())
		{
			for (int j = 0; j < exp.length(); j++)
				s.pop();
		}
		i++;
	}
	while (!s.empty())
	{
		answer += s.top().first;
		s.pop();
	}
	reverse(answer.begin(), answer.end());
	return (answer);
}

int main(void)
{
	string answer, ori, exp;

	cin >> ori >> exp;
	answer = solution(ori, exp);
	if (answer.length() == 0)
		cout << "FRULA\n";
	else
		cout << answer;
	return (0);
}
