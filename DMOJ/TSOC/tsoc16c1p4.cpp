#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char grid[35][50];

bool dfs(int r, int c) {
	bool m = false;
	if (grid[r][c] == 'M') m = true;
	if (grid[r][c] != '#') grid[r][c] = '#', m |= dfs(r + 1, c) | dfs(r - 1, c) | dfs(r, c + 1) | dfs(r, c - 1);
	return m;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, C, cnt = 0;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[i][j] != '#')
				cnt += dfs(i, j);
		}
	}

	cout << cnt << '\n';
	return 0;
}
