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

int ans, N, x[12], y[12], w[12], nxt[12];

void solve() {
	int l = -1;
	for (int i = 0; i < N; i++)
		if (w[i] == -1) { l = i; break; }
	if (l == -1) {
		for (int i = 0; i < N; i++) {
			int idx = i;
			for (int j = 0; j < N && idx != -1; j++) idx = nxt[w[idx]];
			if (idx != -1) { ++ans; break; }
		}
	}
	for (int r = l + 1; r < N; r++) {
		if (w[r] == -1) {
			w[l] = r, w[r] = l;
			solve();
			w[l] = w[r] = -1;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
	memset(nxt, -1, sizeof(nxt));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (x[i] < x[j] && y[i] == y[j] && (nxt[i] == -1 || x[j] < x[nxt[i]]))
				nxt[i] = j;

	memset(w, -1, sizeof(w));
	solve();
	cout << ans << '\n';
	return 0;
}
