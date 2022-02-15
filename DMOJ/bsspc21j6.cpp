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

vector<int> adj[500001];
ll v[500001], dp[500001];

void dfs(int cur, int prev) {
	vector<int> x;
	for (int i : adj[cur]) {
		if (i == prev) continue;
		dfs(i, cur), v[cur] += v[i], x.push_back(i);
	}
	sort(x.begin(), x.end(), [&] (int a, int b) { return v[a] - dp[a] < v[b] - dp[b]; });
	int sz = x.size(), am = max(0, sz - 2 - (cur == 1));
	for (int i = 0; i < am; i++) dp[cur] += v[x[i]];
	for (int i = am; i < sz; i++) dp[cur] += dp[x[i]];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> v[i];
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1, 0);
	cout << dp[1] << '\n';
	return 0;
}
