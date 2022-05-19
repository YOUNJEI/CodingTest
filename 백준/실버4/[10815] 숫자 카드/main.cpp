#include <iostream>
#include <set>
using namespace std;
#define BUFFER_SIZE 500000

int answer[BUFFER_SIZE];
int N, M;

int main(void)
{
	int temp;
	set<int> s;

	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin>>temp;
		s.insert(temp);
	}
	cin>>M;
	for (int i = 0; i < M; i++)
	{
		cin>>temp;
		if (s.find(temp) != s.end())
			answer[i] = 1;
		else
			answer[i] = 0;
	}
	for (int i = 0; i < M; i++)
		cout<<answer[i]<<" ";
	return (0);
}
