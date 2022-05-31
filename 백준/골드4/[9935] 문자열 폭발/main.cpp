#include <iostream>
using namespace std;

string solution(string ori, const string exp)
{
	int i;

	i = 0;
	while (i < ori.length())
	{
		if (ori[i] == exp[0])
		{
			bool flag = true;
			int j = 1;

			while (i + j < ori.length() && j < exp.length())
			{
				if (ori[i + j] != exp[j])
				{
					flag = false;
					break ;
				}
				j++;
			}
			if (flag)
			{
				string temp = ori.substr(0, i);
				temp += ori.substr(i + exp.length());
				ori = temp;
				i -= exp.length();
				if (i < 0)
					i = 0;
			}
			else
				i++;
		}
		else
			i++;
	}
	return (ori);
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
