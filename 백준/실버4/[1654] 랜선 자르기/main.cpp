#include <iostream>
#include <vector>
using namespace std;
#define INTMAX 2147483647

vector<long long> g_len;
int K, N;

int calcDivNum(long long mid) {
	int answer = 0;
	
	for (int i = 0; i < K; i++) {
		answer += (g_len[i] / mid);
	}
	return answer;
}

int binarySearch(long long start, long long end) {
	long long mid = -1;

	while (start <= end) {
		mid = (start + end) / 2;

		int divNum = calcDivNum(mid);
		if (divNum < N)
			end = mid - 1;
		else if (divNum > N)
			start = mid + 1;
		else if (divNum == N)
			start = mid + 1;
	}
	return end;
}

int solve(void) {
	int answer;

	answer = binarySearch(1, INTMAX);
	return answer;
}

int main(void) {
	cin >> K >> N;
	
	for (int i = 0; i < K; i++) {
		int temp;

		cin >> temp;
		g_len.push_back(temp);
	}
	cout << solve();
	return 0;
}
