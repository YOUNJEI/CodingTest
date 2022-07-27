#include <iostream>
#include <vector>
using namespace std;
#define BUFFER_SIZE 8

vector<int> g_arr;
bool g_visit[BUFFER_SIZE];

void print(const vector<int> &make) {
	for (int i = 0; i < make.size(); i++) {
		cout << make[i] << " ";
	}
	cout << "\n";
}

void dfs(vector<int> make, int N, int M) {
	if (make.size() == M) {
		print(make);
		return ;
	}
	for (int i = 0; i < N; i++) {
		if (!g_visit[i]) {
			g_visit[i] = true;
			make.push_back(g_arr[i]);
			dfs(make, N, M);
			g_visit[i] = false;
			make.pop_back();
		}
	}
}

void solve(int N, int M) {
	vector<int> vi;

	for (int i = 0; i < N; i++) {
		g_arr.push_back(i + 1);
	}
	dfs(vi, N, M);
}

int main(void) {
	int N, M;

	cin >> N >> M;
	solve(N, M);
	return 0;
}
