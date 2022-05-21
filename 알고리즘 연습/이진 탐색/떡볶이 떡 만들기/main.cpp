#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<long long> vi;

long long getSum(int start, int end)
{
	long long sum = 0;

	for (int i = start; i <= end; i++)
		sum += vi[i];
	return (sum);
}

int __binary_search(int start, int end)
{
	if (start >= end)
		return (start + 1);
	int mid = (start + end) / 2;
	long long sum = getSum(start, mid);
	if (sum + (vi[mid] * (vi.size() - mid - 1)) == M)
			return (mid);
	else if (sum + (vi[mid] * (vi.size() - mid - 1)) > M)
		return __binary_search(start, mid - 1);
	else
		return __binary_search(mid + 1, end);
}


int main(void)
{
	cin>>N>>M;
	long long temp;
	long long sum = 0;

	for (int i = 0; i < N; i++)
	{
		cin>>temp;
		sum += temp;
		vi.push_back(temp);
	}
	sort(vi.begin(), vi.end());
	cout<<vi[__binary_search(0, vi.size() - 1)];
	return (0);
}
