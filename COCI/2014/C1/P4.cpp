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

int p[500001], deg[500001], ans;
bool vis[500001];

void dfs(int cur, bool b) {
	if (vis[cur]) return;
	vis[cur] = true, ans += b;
	if (--deg[p[cur]] == 0 || b) dfs(p[cur], b ^ 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i], ++deg[p[i]];
	for (int i = 1; i <= N; i++)
		if (deg[i] == 0) dfs(i, true);
	for (int i = 1; i <= N; i++) dfs(i, false);
	cout << ans << '\n';
	return 0;
}
