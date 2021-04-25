#include <bits/stdc++.h>

using namespace std;

char grid[1000][2000];
bool vis[1000][2000];
int N, minr, maxr, minc, maxc;

void find_patch(int r, int c) {
	if (r >= 0 && r < N && c >= 0 && c < N << 1 && grid[r][c] == '#' && !vis[r][c]) {
		vis[r][c] = true;
		find_patch(r + 1, c); find_patch(r, c + 1); find_patch(r - 1, c); find_patch(r, c - 1);
		minr = min(minr, r - 1), maxr = max(maxr, r + 1), minc = min(minc, c - 1), maxc = max(maxc, c + 1);
	}
}

bool valid() {
	int rlen = maxr - minr + 1, clen = maxc - minc + 1, M = (clen - 5) / 2;
	if (M <= 0 || rlen != 4 + M / 5 + (2 * M + 2) / 3 || clen != 2 * M + 5) return false;

	for (int i = 1; i <= 3; i++) if (grid[minr][minc + M + i] != '.') return false;
	minr++;

	for (int i = 0; i < M / 5; i++, minr++) if (grid[minr][minc + M + 1] != '.' || grid[minr][minc + M + 2] != '#' || grid[minr][minc + M + 3] != '.') return false;

	for (int i = 0; i < 2 * M + 5; i++) if (grid[minr][minc + i] != (i == M + 2 ? '#' : '.')) return false;
	minr++;

	for (int i = 0; i < 1 + (2 * M + 2) / 3; i++, minr++)
		for (int j = 0; j < 2 * M + 5; j++) if (grid[minr][minc + j] != (j > 0 && j < 2 * M + 4 ? '#' : '.')) return false;

	for (int i = 0; i < 2 * M + 5; i++) if (grid[minr][minc + i] != '.') return false;
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> grid[i];

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N << 1; j++) {
			if (!vis[i][j] && grid[i][j] == '#') {
				minr = minc = INT_MAX, maxr = maxc = 0;
				find_patch(i, j); cnt += valid();
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}
