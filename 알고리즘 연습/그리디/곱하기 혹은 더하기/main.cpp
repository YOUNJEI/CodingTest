#include <iostream>
using namespace std;

int solution(string s)
{
	int sum = 0;
	int i;

	i = 0;
	while (s[i] == '0')
		i++;
	if (s[i] == '\0')
		return (0);
	sum = s[i++] - '0';
	while (i < s.length())
	{
		if (s[i] != '0' && s[i] != '1')
			sum *= (s[i] - '0');
		else
			sum += (s[i] - '0');
		i++;
	}
	return (sum);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		cout<<solution(argv[1]);
	}
	return (0);
}
