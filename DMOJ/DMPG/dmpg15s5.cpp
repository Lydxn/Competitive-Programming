#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool grid[10002][10002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, x, y, w, h, cnt = 0;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y >> w >> h; ++x, ++y;
		grid[x][y] ^= true, grid[x + w][y] ^= true, grid[x][y + h] ^= true, grid[x + w][y + h] ^= true;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			grid[i][j] ^= grid[i - 1][j] ^ grid[i][j - 1] ^ grid[i - 1][j - 1];
			cnt += grid[i][j];
		}
	}
	cout << cnt << '\n';
	return 0;
}
