#include <iostream>

using namespace std;

int* g_topDown;
int* g_bottomUp;

int naiveRecursion(int n)
{
	if (n <= 1)
		return (n);
	return naiveRecursion(n - 1) + naiveRecursion(n - 2);
}

int topDown(int n)
{
	if (n <= 2)
		return (1);
	if (g_topDown[n] == 0)
		g_topDown[n] = topDown(n - 1) + topDown(n - 2);
	return (g_topDown[n]);
}

int bottomUp(int n)
{
	g_bottomUp[0] = 0;
	g_bottomUp[1] = 1;

	for (int i = 2; i <=n; i++)
		g_bottomUp[i] = g_bottomUp[i - 1] + g_bottomUp[i - 2];
	return (g_bottomUp[n]);
}

int main(void)
{
	int n = 100;
	g_topDown = new int[n + 1];
	g_bottomUp = new int[n + 1];
	cout<<topDown(n)<<endl;
	cout<<bottomUp(n)<<endl;
	//cout<<naiveRecursion(n)<<endl;
}
