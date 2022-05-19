#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	int N, M;
	string temp;
	set<string> s;
	int answer = 0;

	cin>>N>>M;
	for (int i = 0; i < N; i++)
	{
		cin>>temp;
		s.insert(temp);
	}
	for (int i = 0; i < M; i++)
	{
		cin>>temp;
		if (s.find(temp) != s.end())
			answer++;
	}
	cout<<answer;
	return (0);
}
