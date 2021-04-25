#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char grid[200][8000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, h, mx = 0, idx = 0;
	cin >> N;

	memset(grid, ' ', sizeof(grid));
	while (N--) {
		cin >> h;
		for (int i = 0; i < h; i++)
			for (int j = i; j < 2 * h - 1 - i; j += 2)
				grid[i][idx + j] = '^';
		idx += 2 * h, mx = max(mx, h);
	}

	for (int i = mx - 1; i >= 0; i--) {
		for (int j = 0; j < idx; j++) cout << grid[i][j];
		cout << '\n';
	}
	return 0;
}
