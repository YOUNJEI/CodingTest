#include <iostream>
#include <vector>
using namespace std;

int g_dp0[41];
int g_dp1[41];

void fibonacci(int n)
{
	if (g_dp0[n] == 0)
		g_dp0[n] = 
}

void 


int main(void)
{
	int T, temp;
	vector<int> vi;

	cin>>T;
	for (int i = 0; i < T; i++)
	{
		cin>>temp;
		vi.push_back(temp);
	}
	for (int i = 0; i < T; i++)
	{
		fibonacci(vi[i]);
	}
	return (0);
}
