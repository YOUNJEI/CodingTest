#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	string temp;
	vector<char> vc;
	int sum = 0;

	cin>>temp;
	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] >= '0' && temp[i] <= '9')
			sum += temp[i] - '0';
		else
			vc.push_back(temp[i]);
	}
	sort(vc.begin(), vc.end());
	for (int i = 0; i < vc.size(); i++)
		cout<<vc[i];
	if (sum != 0)
		cout<<sum;
	return (0);
}
