#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int N, g[25][25], p3[9], t[3][3];
bool vis[25][25][19683];
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
unordered_set<int> ans;

bool check(int st) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			t[i][j] = st / p3[i * 3 + j] % 3;
	bool yay = false;
	for (int i = 0; i < 3; i++) {
		yay |= t[i][0] == 1 && t[i][1] == 2 && t[i][2] == 2;
		yay |= t[0][i] == 1 && t[1][i] == 2 && t[2][i] == 2;
		yay |= t[i][0] == 2 && t[i][1] == 2 && t[i][2] == 1;
		yay |= t[0][i] == 2 && t[1][i] == 2 && t[2][i] == 1;
	}
	yay |= t[0][0] == 1 && t[1][1] == 2 && t[2][2] == 2;
	yay |= t[0][2] == 1 && t[1][1] == 2 && t[2][0] == 2;
	yay |= t[0][0] == 2 && t[1][1] == 2 && t[2][2] == 1;
	yay |= t[0][2] == 2 && t[1][1] == 2 && t[2][0] == 1;
	return yay;
}

void dfs(int r, int c, int st) {
	if (vis[r][c][st]) return;
	vis[r][c][st] = true;
	if (check(st)) { ans.insert(st); return; }
	for (pii d : dir) {
		int nr = r + d.first, nc = c + d.second;
		if (r < 0 || r >= N || c < 0 || c >= N || g[nr][nc] == 0) continue;
		int nst = st;
		if (g[nr][nc] != 1) {
			int br = g[nr][nc] >> 4, bc = (g[nr][nc] >> 2) & 3, m = (g[nr][nc] & 3) == 2 ? 1 : 2;
			int p = p3[br * 3 + bc];
			if (nst / p % 3 == 0) nst += p * m;
		}
		dfs(nr, nc, nst);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	p3[0] = 1;
	for (int i = 1; i < 9; i++) p3[i] = p3[i - 1] * 3;

	int sr = -1, sc = -1; char a, b, c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a >> b >> c;
			if (a == 'B') sr = i, sc = j;
			if (a == '#') g[i][j] = 0;
			else if (a == '.' || a == 'B') g[i][j] = 1;
			else g[i][j] = (b - '1') << 4 | (c - '1') << 2 | (a == 'M' ? 2 : 3);
		}
	}
	dfs(sr, sc, 0);
	cout << ans.size() << '\n';
	return 0;
}
