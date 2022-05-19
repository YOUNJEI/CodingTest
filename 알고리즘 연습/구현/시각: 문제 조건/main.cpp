#include <iostream>
using namespace std;

int solution(int N)
{
	if (N < 3)
		return (1575 * (N + 1));
	if (N < 13)
		return (1575 * (N) + 3600);
	if (N < 23)
		return (1575 * (N - 1) + 7200);
	if (N == 23)
		return (1575 * (N - 2) + 10800);
	return (-1);
}

int solution2(int N)
{
	int count = 0;

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				if (i % 10 == 3 ||
					j / 10 == 3 || j % 10 == 3 ||
						k / 10 == 3 || k % 10 == 3)
					count++;
			}
		}
	}
	return (count);
}

int main(void)
{
	int N;
	cin>>N;
	
	cout<<solution(N)<<'\n';
	cout<<solution2(N)<<'\n';
	return (0);
}
