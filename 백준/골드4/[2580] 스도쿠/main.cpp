#include <iostream>
#include <set>
using namespace std;
#define BUFFER_SIZE 9

int g_arr[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE + 1];

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

bool dfs(int r, int c, set<int> rowD[BUFFER_SIZE], set<int> colD) {
	if (r == BUFFER_SIZE - 1 && c == BUFFER_SIZE) {
		return true;
	}
	if (c == BUFFER_SIZE) {
		colD.clear();
		if (dfs(r + 1, 0, rowD, colD))
			return true;
		return false;
	}
	if (r < BUFFER_SIZE && c < BUFFER_SIZE) {
		if (g_arr[r][c] == 0) {
			for (int i = 1; i <= 9; i++) {
				if (rowD[c].find(i) == rowD[c].end() && colD.find(i) == colD.end() && !g_visit[findSubTable(r, c)][i]) {
					g_arr[r][c] = i;
					rowD[c].insert(i);
					colD.insert(i);
					g_visit[findSubTable(r, c)][i] = true;
					if (dfs(r, c + 1, rowD, colD))
						return true;
					g_arr[r][c] = 0;
					rowD[c].erase(rowD[c].find(i));
					colD.erase(colD.find(i));
					g_visit[findSubTable(r, c)][i] = false;
				}
			}
		}
		else {
			if (rowD[c].find(g_arr[r][c]) == rowD[c].end() && colD.find(g_arr[r][c]) == colD.end() && !g_visit[findSubTable(r, c)][g_arr[r][c]]) {
				rowD[c].insert(g_arr[r][c]);
				colD.insert(g_arr[r][c]);
				g_visit[findSubTable(r, c)][g_arr[r][c]] = true;
				if (dfs(r, c + 1, rowD, colD))
					return true;
			}
		}
	}
	return false;
}

void solve(void) {
	set<int> temp1[BUFFER_SIZE];
	set<int> temp2;

	dfs(0, 0, temp1, temp2);
	cout << "\n";
	print();
}

int main(void) {
	for (int i = 0; i < BUFFER_SIZE; i++) {
		for (int j = 0; j < BUFFER_SIZE; j++) {
			cin >> g_arr[i][j];
		}
	}
	solve();
	return 0;
}
