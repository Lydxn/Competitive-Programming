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

unordered_map<string, vector<string>> adj;
unordered_map<string, bool> vis;
unordered_map<string, string> par;
queue<string> q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m; string a, b;
	cin >> m >> n;
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}

	while (n--) {
		cin >> a >> b;
		q = {}; q.push(a);
		vis.clear(); vis[a] = true;
		par.clear(); par[a] = "-1";

		while (!q.empty()) {
			string cv = q.front(); q.pop();
			for (string i : adj[cv])
				if (!vis[i]) vis[i] = true, q.push(i), par[i] = cv;
		}

		vector<char> ans;
		while (b != "-1") ans.push_back(b[0]), b = par[b];
		reverse(ans.begin(), ans.end());
		for (char i : ans) cout << i;
		cout << '\n';
	}
	return 0;
}
