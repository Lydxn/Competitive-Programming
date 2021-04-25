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

vector<int> adj[10], top;
bool vis[10];

// topsort only works if passcode contains no repeated digits (which it does, apparently)
void dfs(int cur) {
	if (vis[cur]) return;
	vis[cur] = true;
	for (int i : adj[cur]) dfs(i);
	top.push_back(cur);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("p079_keylog.txt", "r", stdin);
	string s;
	while (cin >> s) {
		int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0';
		adj[a].push_back(b), adj[b].push_back(c);
	}

	for (int i = 0; i < 10; i++)
		if (!adj[i].empty()) dfs(i);
	for (int i = top.size() - 1; i >= 0; i--) cout << top[i];
	cout << '\n';
	return 0;
}
