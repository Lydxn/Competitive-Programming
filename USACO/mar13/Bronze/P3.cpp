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

int N, K, c[15], ans;
char g[50][50];

void solve(int idx) {
	if (idx == N) { ++ans; return; }
	for (int i = 0; i < 3; i++) {
		c[idx] = i;
		for (int j = 0; j < idx; j++)
			if ((g[idx][j] == 'S' && c[j] != c[idx]) || (g[idx][j] == 'D' && c[j] == c[idx]))
				goto nxt;
		solve(idx + 1); nxt:;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);

	int x, y; char t;
	cin >> N >> K;
	for (int i = 0; i < K; i++)
		cin >> t >> x >> y, g[x - 1][y - 1] = g[y - 1][x - 1] = t;
	solve(0);
	cout << ans << '\n';
	return 0;
}