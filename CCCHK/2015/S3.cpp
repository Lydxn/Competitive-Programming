#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int BASE = 3, MOD = 1000000007;
ll h1[2000][2001], h2[2000][2001], v1[2000][2001], v2[2000][2001], pre[2001];
bool M[2000][2000];
int R, C;

// [l, r)
int shash(int l, int r, ll* hsh) {
	return (hsh[l] - hsh[r] * pre[r - l] % MOD + MOD) % MOD;
}

pii f(int sz) {
	int tsz = sz * 2 + 1;
	for (int i = 0; i < R - tsz + 1; i++) {
		for (int j = 0; j < C - tsz + 1; j++) {
			int p1 = shash(j, j + sz, h1[i + sz]), p2 = shash(i, i + sz, v1[j + sz]),
				p3 = shash(C - tsz - j, C - tsz - j + sz, h2[i + sz]), p4 = shash(R - tsz - i, R - tsz - i + sz, v2[j + sz]);
			if (p1 == p2 && p1 == p3 && p1 == p4) {
				return {i + sz + 1, j + sz + 1};
			}
		}
	}
	return {-1, -1};
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> M[i][j];
		}
	}

	pre[0] = 1;
	for (int i = 1; i <= max(R, C); i++) pre[i] = pre[i - 1] * BASE % MOD;

	for (int i = 0; i < R; i++)
		for (int j = C - 1; j >= 0; j--)
			h1[i][j] = (h1[i][j + 1] * BASE + M[i][j] + 1) % MOD, h2[i][j] = (h2[i][j + 1] * BASE + M[i][C - j - 1] + 1) % MOD;

	for (int i = 0; i < C; i++)
		for (int j = R - 1; j >= 0; j--)
			v1[i][j] = (v1[i][j + 1] * BASE + M[j][i] + 1) % MOD, v2[i][j] = (v2[i][j + 1] * BASE + M[R - j - 1][i] + 1) % MOD;

	int l = 0, r = (min(R, C) - 1) / 2; pii ans;
	while (l <= r) {
		int mid = (l + r) / 2; pii cur = f(mid);
		if (cur != make_pair(-1, -1)) l = mid + 1, ans = cur;
		else r = mid - 1;
	}
	cout << l - 1 << ' ' << ans.first << ' ' << ans.second << '\n';
	return 0;
}
