#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int N, x;
	vector<int> vi;

	cin>>N>>x;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin>>temp;
		vi.push_back(temp);
	}
	cout<<upper_bound(vi.begin(), vi.end(), x) - lower_bound(vi.begin(), vi.end(), x)<<'\n';
	return (0);
}
