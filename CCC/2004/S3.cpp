#include <bits/stdc++.h>

using namespace std;

string grid[10][9];
int ans[10][9];
bool found[10][9];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> grid[i][j];
		}
	}

	memset(ans, -1, sizeof(ans));
	for (int _ = 0; _ < 900; _++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				string cell = grid[i][j];
				if (!found[i][j]) {
					if (isdigit(cell[0])) ans[i][j] = stoi(cell);
					else {
						int sum = 0;
						for (int k = 0; k < cell.size(); k += 3) {
							int r = cell[k] - 'A', c = cell[k + 1] - '1';
							if (!found[r][c]) goto nxt;
							sum += ans[r][c];
						}
						ans[i][j] = sum;
					}
					found[i][j] = true; nxt:;
				}
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (ans[i][j] == -1) cout << "* ";
			else cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
