#include <iostream>
using namespace std;

int *g_arr = NULL;

int main(void)
{
	int arr[] = {7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2};
	int max = 0;
	for (int i = 0; i < 15; i ++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	g_arr = new int(max + 1);
	for (int i = 0; i < max + 1; i ++)
		g_arr[i] = 0;
	for (int i = 0; i < 15; i++)
	{
		g_arr[arr[i]]++;
	}
	for (int i = 0; i < max + 1; i++)
	{
		for (int j = 0; j < g_arr[i]; j++)
		{
			cout<<i;
		}
	}
	return (0);
}
