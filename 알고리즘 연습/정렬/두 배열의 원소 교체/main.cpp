#include <iostream>
using namespace std;

void __quicksort(int *arr, int start, int end)
{
	if (start >= end)
		return ;
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		while (right > start && arr[right] >= arr[pivot])
			right--;
		if (left > right)
		{
			int temp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = temp;
		}
		else
		{
			int temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;
		}
	}
	__quicksort(arr, start, right - 1);
	__quicksort(arr, right + 1, end);
}

int main(void)
{
	int N, K;
	int answer = 0;

	cin>>N>>K;
	int *arrA = new int[N];
	int *arrB = new int[N];
	for (int i = 0; i < N; i++)
		cin>>arrA[i];
	for (int i = 0; i < N; i++)
		cin>>arrB[i];
	__quicksort(arrA, 0, N - 1);
	__quicksort(arrB, 0, N - 1);

	for (int i = 0; i < N; i++)
		answer += arrA[i];

	int idxA = 0;
	int idxB = N - 1;
	for (int i = 0; i < K; i++)
	{
		if (arrA[idxA] < arrB[idxB])
		{
			answer += arrB[idxB];
			answer -= arrA[idxA];
			idxA++;
			idxB--;
		}
		else
			break;
	}
	cout<<answer;
	delete[] arrA;
	delete[] arrB;
}
