#include <iostream>
using namespace std;

int main(void)
{
	int N = 10;
	int arr[] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

	for (int i = 1; i < N; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
			else
				break ;
		}
	}
	for (int i = 0; i < N; i++)
		cout<<arr[i];
}
