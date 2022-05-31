#include <iostream>
using namespace std;

int digitCount[10];
string N;

string solution(void)
{
	string answer = "";

	for (int i = 0; i < N.length(); i++)
		digitCount[N[i] - '0']++;
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < digitCount[i]; j++)
		{
			answer += i + '0';
		}
	}
	return (answer);
}

int main(void)
{
	cin >> N;
	cout << solution() << '\n';
	return (0);
}
