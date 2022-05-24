#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define NANO 10000000
long long x;
long long n;
vector<long long> vi;
long long g_answerLeft = 0;
long long g_answerRight = 0;

bool binarySearch(long long fix, long long start, long long end)
{
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		
		if (vi[fix] + vi[mid] == x * NANO)
		{
			g_answerLeft = fix;
			g_answerRight = mid;
			return (true);
		}
		else if (vi[fix] + vi[mid] > x * NANO)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (false);
}

pair<long long, long long> solution(void)
{
	long long temp;

	for (long long i = 0; i < vi.size() - 1; i++)
	{
		temp = binarySearch(i, i + 1, vi.size() - 1);
		if (temp)
			return (make_pair(vi[g_answerLeft], vi[g_answerRight]));
	}
	return (make_pair(-1, -1));
}

int main(void)
{
	ios::base::sync_with_stdio(0);
	cin.tie(0);
	long long count = 0;
	vector<pair<long long, long long>> answer;
	string s;

	while (getline(cin, s))
	{
		x = s[0] - '0';
		cin>>n;

		long long temp;
		vi.clear();
		for (long long i = 0; i < n; i++)
		{
			cin>>temp;
			vi.push_back(temp);
		}
		cin.ignore();
		sort(vi.begin(), vi.end());
		answer.push_back(solution());
		count++;
	}
	for (long long i = 0; i < count; i++)
	{
		if(answer[i].first != -1)
			cout<<"yes "<<answer[i].first<<" "<<answer[i].second<<'\n';
		else
			cout<<"danger\n";
	}
	return (0);
}
