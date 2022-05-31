#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define BUFFER_SIZE 30
string g_str[BUFFER_SIZE];
int T;

int check(string s, bool flag)
{
	int start, end;

	start = 0;
	end = s.length() - 1;
	while (end >= start)
	{
		if (s[start] != s[end])
		{
			if (s[start + 1] != s[end] && s[start] != s[end - 1])
				return (2);

			if (flag)
			{
				int cases[2];

				flag = false;

				string temp = "";
				temp += s.substr(0, start);
				temp += s.substr(start + 1);
				cases[0] = check(temp, false);

				temp = "";
				temp += s.substr(0, end);
				temp += s.substr(end + 1);
				cases[1] = check(temp, false);

				if (!cases[0] || !cases[1])
					return (1);
				else
					return (2);
			}
			else
				return (2);
		}
		start++;
		end--;
	}
	// 회문
	return (0);
}

vector<int> solve(void)
{
	vector<int> answer;

	for (int i = 0; i < T; i++)
	{
		int flag = check(g_str[i], true);
		answer.push_back(flag);
	}
	return (answer);
}

int main(void)
{
	cin >> T;
	for (int i = 0; i < T; i++)
		cin >> g_str[i];
	vector<int> vi = solve();
	for (int i = 0; i < vi.size(); i++)
		cout<<vi[i]<<'\n';
	return (0);
}
