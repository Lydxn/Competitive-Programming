#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;
ll dp1[2001][2001], dp2[2001][2001];

ll solve1(int a, int b) {
	if (a < 0 || b < 0) return 0;
	if (a == 0 && b == 0) return 1;
	if (a <= b) return 0;
	if (dp1[a][b] != -1) return dp1[a][b];
	return dp1[a][b] = (solve1(a - 1, b) + solve1(a, b - 1)) % MOD;
}

ll solve2(int a, int b) {
	if (a < 0 || b < 0) return 0;
	if (a == 0 && b == 0) return 1;
	if (a > b) return 0;
	if (dp2[a][b] != -1) return dp2[a][b];
	return dp2[a][b] = (solve2(a - 1, b) + solve2(a, b - 1)) % MOD;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, a, b; string game;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> game;
		a = stoi(game.substr(0, game.find('-'))), b = stoi(game.substr(game.find('-') + 1));

		memset(dp1, -1, sizeof(dp1)); memset(dp2, -1, sizeof(dp2));
		cout << "Case #" << i << ": " << solve1(a, b) << ' ' << solve2(min(a, b), b) << '\n';
	}
	return 0;
}
