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

vector<int> adj[100001];
bool vis[100001];
queue<int> q;
int par[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}

	memset(par, -1, sizeof(par));
	q.push(1), vis[1] = true;
	while (!q.empty()) {
		int cv = q.front(); q.pop();
		for (int i : adj[cv])
			if (!vis[i]) q.push(i), vis[i] = true, par[i] = cv;
	}

	if (!vis[n]) cout << "IMPOSSIBLE\n";
	else {
		vector<int> ans;
		for (; n != -1; n = par[n]) ans.push_back(n);
		cout << ans.size() << '\n';
		for (int i = int(ans.size()) - 1; i >= 0; i--)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}
