#include <iostream>
#include <vector>
using namespace std;
#define BUFFER_SIZE 100
bool g_charset[BUFFER_SIZE][128];
string g_str[BUFFER_SIZE];
int N;

bool check(string s, int testCaseIdx)
{
	int i, size;

	i = 0;
	size = s.length();
	while (i < size)
	{
		// s[i]가 사용이 안되었다면.
		if (!g_charset[testCaseIdx][s[i]])
		{
			int j = i;
			while (j < size)
			{
				if (s[j] == s[i])
					j++;
				else
					break ;
			}
			g_charset[testCaseIdx][s[i]] = true;
			i = j;
		}
		// 사용이 되었으면 그룹 단어가 아님.
		else
			return (false);
	}
	return (true);
}

int solution(void)
{
	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		if (check(g_str[i], i))
			answer++;
	}
	return (answer);
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> g_str[i];
	cout << solution() << '\n';
	return (0);
}
