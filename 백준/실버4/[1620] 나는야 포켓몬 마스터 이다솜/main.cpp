#include <iostream>
#include <map>
#include <string>
using namespace std;
#define BUFFER_SIZE 100000
string g_arr[BUFFER_SIZE];
string g_answer[BUFFER_SIZE];

int main(void)
{
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	map<string, int> m;
	string temp;

	cin>>N>>M;
	for (int i = 0; i < N; i++)
	{
		cin>>temp;
		m.insert(make_pair(temp, i + 1));
		g_arr[i] = temp;
	}
	for (int i = 0; i < M; i++)
	{
		cin>>temp;
		if (temp[0] >= '0' && temp[0] <= '9')
			g_answer[i] = g_arr[stoi(temp) - 1];
		else
			g_answer[i] = to_string(m[temp]);
	}
	for (int i = 0; i < M; i++)
		cout<<g_answer[i]<<'\n';
	return (0);
}
