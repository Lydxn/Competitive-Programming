#include <bits/stdc++.h>

using namespace std;

int dp[3][301][3][301];

int solve(int h1, int w1, int h2, int w2) {
	if (h1 == 1 && w1 == 1 && h2 == 1 && w2 == 1) return 0;
	if (dp[h1][w1][h2][w2] != -1) return dp[h1][w1][h2][w2];
	bool res = false;
	// option 1
	for (int i = 1; i <= w1 - 1; i++)
		res |= !solve(h1, i, h1, w1 - i);
	for (int i = 1; i <= w2 - 1; i++)
		res |= !solve(h2, i, h2, w2 - i);
	if (h1 == 2)
		res |= !solve(1, w1, 1, w1);
	if (h2 == 2)
		res |= !solve(1, w2, 1, w2);
	// option 2
	for (int i = 1; i <= 10; i++)
		if (w1 - i > 0)
			res |= !solve(h1, w1 - i, h2, w2);
	for (int i = 1; i <= 10; i++) {
		if (w2 - i > 0)
			res |= !solve(h1, w1, h2, w2 - i);
	}
	if (h1 == 2)
		res |= !solve(1, w1, h2, w2);
	if (h2 == 2)
		res |= !solve(h1, w1, 1, w2);
	return dp[h1][w1][h2][w2] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int h1, w1, h2, w2;
	cin >> h1 >> w1 >> h2 >> w2;
	memset(dp, -1, sizeof(dp));
	cout << (solve(h1, w1, h2, w2) ? "W" : "L") << '\n';
	return 0;
}