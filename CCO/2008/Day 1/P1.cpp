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

vector<int> top, adj[101];
bool vis[101], c[101], in[101];
string mp[101];

void dfs(int cur) {
	if (c[cur]) { cout << "Impossible\n"; exit(0); }
	if (vis[cur]) return;
	vis[cur] = true, c[cur] = true;
	for (int i : adj[cur]) dfs(i);
	top.push_back(cur);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b; string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> a >> b;
		adj[a].push_back(b), in[b] = true, mp[b] = s;
	}

	for (int i = 1; i <= 100; i++)
		if (in[i]) memset(c, false, sizeof(c)), dfs(i);
	for (int t : top)
		cout << mp[t] << '\n';
	return 0;
}
