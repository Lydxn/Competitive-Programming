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

vector<int> adj[50001];
int col[50001], sz;

int dfs(int cur, bool b) {
	if (col[cur]) {
		if (col[cur] != b + 1) { cout << "-1\n"; exit(0); }
		return 0;
	}
	col[cur] = b + 1, ++sz;
	
	int cnt = b;
	for (int i : adj[cur]) cnt += dfs(i, b ^ 1);
	return cnt;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("decorate.in", "r", stdin);
	freopen("decorate.out", "w", stdout);

	int N, M, A, B;
	cin >> N >> M;
	while (M--) {
		cin >> A >> B;
		adj[A].push_back(B), adj[B].push_back(A);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (col[i]) continue;
		sz = 0; int cur = dfs(i, false);
		ans += max(cur, sz - cur);
	}
	cout << ans << '\n';
	return 0;
}
