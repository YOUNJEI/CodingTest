#include <iostream>
using namespace std;

int main(void)
{
	int arr[] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
	int temp;

	for (int i = 0; i < 10; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[min_idx] > arr[j])
				min_idx = j;
		}
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
	for (int i = 0 ; i < 10; i++)
		cout<<arr[i];
	return (0);
}
