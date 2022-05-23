/* 타인 질문 게시글 해결 하기 위한 */
/* 테스트용 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

int count_one;
int count_zero;

bool check[41] = { false, };
int memo_one[41] = { -1, };
int memo_zero[41] = { -1, };

void fibonacci(int n) {
	if (!check[n]) {
		if (n == 0)
			count_zero++;
		else if (n == 1)
			count_one++;
		else {
			fibonacci(n - 2);
			fibonacci(n - 1);
		}
	}
	else {
		count_zero += memo_zero[n];
		count_one += memo_one[n];
	}
}

int main() {

	int T, num;
	vector<pair<int, int>> answer;

	scanf("%d", &T);
	int i = T;
	while (i != 0) {

		scanf("%d", &num);
		for (int i = 0; i <= num; i++)
		{
			if (check[i])
				continue ;
			count_one = 0;
			count_zero = 0;

			fibonacci(i);
			check[i] = true;
			memo_zero[i] = count_zero;
			memo_one[i] = count_one;
		}
		answer.push_back(make_pair(memo_zero[num], memo_one[num]));
		i--;
	}
	for (i = 0; i < T; i++)
		cout<<answer[i].first<<" "<<answer[i].second<<'\n';
	return 0;
}
