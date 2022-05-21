#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int> &vi, int target, int start, int end)
{
	if (start > end)
		return (-1);
	int mid = (start + end) / 2;
	
	if (vi[mid] == target)
		return (mid);
	else if (vi[mid] > target)
		return binary_search(vi, target, start, mid - 1);
	else
		return binary_search(vi, target, mid + 1, end);
}

int main(void)
{
	int N, target;
	vector<int> vi;

	cin>>N>>target;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin>>temp;
		vi.push_back(temp);
	}
	sort(vi.begin(), vi.end());
	int result = binary_search(vi, target, 0, vi.size() - 1);
	if (result == -1)
		cout<<"X";
	else
		cout<<result + 1;
	return (0);
}
