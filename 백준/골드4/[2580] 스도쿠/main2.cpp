#include <iostream>
using namespace std;

#define BUFFER_SIZE 9
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
bool g_col[BUFFER_SIZE][10];
bool g_row[BUFFER_SIZE][10];
bool g_subtable[BUFFER_SIZE][10];

int findSubTable(int r, int c) {
	int rCal = r / 3;
	int cCal = c / 3;
	
	return (rCal * 3) + (cCal);
}

void print(void) {
	for (int i = 0; i < BUFFER_SIZE; i++) {
		for (int j = 0; j < BUFFER_SIZE; j++) {
			cout << g_arr[i][j] << " ";
		}
		cout << "\n";
	}
}

bool dfs(int r, int c) {
	if (r == BUFFER_SIZE - 1 && c == BUFFER_SIZE) {
		return true;
	}
	if (c == BUFFER_SIZE) {
		if (dfs(r + 1, 0))
			return true;
		return false;
	}
	if (r < BUFFER_SIZE && c < BUFFER_SIZE) {
		if (g_arr[r][c] == 0) {
			for (int i = 1; i <= 9; i++) {
				if (!g_row[r][i] && !g_col[c][i] && !g_subtable[findSubTable(r, c)][i]) {
					g_row[r][i] = true;
					g_col[c][i] = true;
					g_subtable[findSubTable(r, c)][i] = true;
					g_arr[r][c] = i;
					if (dfs(r, c + 1))
						return true;
					g_row[r][i] = false;
					g_col[c][i] = false;
					g_subtable[findSubTable(r, c)][i] = false;
					g_arr[r][c] = 0;
				}
			}
		}
		else {
			if (dfs(r, c + 1))
				return true;
			/*
			if (g_row[r][g_arr[r][c]] || g_col[c][g_arr[r][c]] || g_subtable[findSubTable(r, c)][g_arr[r][c]])
				return false;
			g_row[r][g_arr[r][c]] = true;
			g_col[c][g_arr[r][c]] = true;
			g_subtable[findSubTable(r, c)][g_arr[r][c]] = true;
			if (dfs(r, c + 1))
				return true;
			g_row[r][g_arr[r][c]] = false;
			g_col[c][g_arr[r][c]] = false;
			g_subtable[findSubTable(r, c)][g_arr[r][c]] = false;
			*/
		}
	}
	return false;
}

void solve(void) {
	dfs(0, 0);
	print();
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < BUFFER_SIZE; i++) {
		for (int j = 0; j < BUFFER_SIZE; j++) {
			cin >> g_arr[i][j];
			if (g_arr[i][j]) {
				g_row[i][g_arr[i][j]] = true;
				g_col[j][g_arr[i][j]] = true;
				g_subtable[findSubTable(i, j)][g_arr[i][j]] = true;
			}
		}
	}
	solve();
	return 0;
}
