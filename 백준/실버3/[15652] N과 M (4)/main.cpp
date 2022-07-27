#include <iostream>
#include <vector>
using namespace std;

vector<int> g_arr;

void print(const vector<int> &make) {
	for (int i = 0; i < make.size(); i++) {
		cout << make[i] << " ";
	}
	cout << "\n";
}

void dfs(vector<int> make, int idx, int N, int M) {
	if (make.size() == M) {
		print(make);
		return ;
	}
	for (int i = idx; i < N; i++) {
		make.push_back(g_arr[i]);
		dfs(make, i, N, M);
		make.pop_back();
	}
}

void solve(int N, int M) {
	vector<int> vi;

	for (int i = 0; i < N; i++) {
		g_arr.push_back(i + 1);
	}
	dfs(vi, 0, N, M);
}

int main(void) {
	int N, M;

	cin >> N >> M;
	solve(N, M);
	return 0;
}
