#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vc;
vector<int> vb;
int N, M;

void solution(void)
{
	int t = 1;
	int size = vb.size();
	int i, j;

	sort(vc.begin(), vc.end());
	sort(vb.begin(), vb.end());
	if (vb[M - 1] > vc[N - 1])
	{
		cout<<"-1";
		return ;
	}
	while(size)
	{
		i = vc.size() - 1;
		while (i >= 0)
		{
			j = vb.size() - 1;
			while (j >= 0)
			{
				if (vc[i] >= vb[j])
				{
					vb.erase(vb.begin() + j);
					size--;
					break ;
				}
				j--;
			}
			i--;
		}
		t++;
	}
	cout<<t - 1;
}

int main(void)
{
	int temp;

	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin>>temp;
		vc.push_back(temp);
	}
	cin>>M;
	for (int i = 0; i < M; i++)
	{
		cin>>temp;
		vb.push_back(temp);
	}
	solution();
	return (0);
}
