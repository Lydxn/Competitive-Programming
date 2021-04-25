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

vector<int> adj[2501], radj[2501];
int a[5000], b[5000], x[5000];
ll d[2501];
bool vis1[2501], vis2[2501];

void dfs1(int cur) {
	if (vis1[cur]) return;
	vis1[cur] = true;
	for (int i : adj[cur]) dfs1(i);
}

void dfs2(int cur) {
	if (vis2[cur]) return;
	vis2[cur] = true;
	for (int i : radj[cur]) dfs2(i);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> x[i];
		adj[a[i]].push_back(b[i]);
		radj[b[i]].push_back(a[i]);
	}
	dfs1(1); dfs2(n);
	
	memset(d, -INFL, sizeof(d)); d[1] = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m; j++)
			if (d[a[j]] != -INFL)
				d[b[j]] = max(d[b[j]], d[a[j]] + x[j]);
	for (int i = 0; i < m; i++)
		if (vis1[a[i]] && vis2[b[i]] && d[a[i]] != -INFL && d[a[i]] + x[i] > d[b[i]])
			{ cout << "-1\n"; return 0; }
	cout << d[n] << '\n';
	return 0;
}
