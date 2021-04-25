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

string w[100000];
unordered_map<string, int> mp;
vector<int> adj[100000], pre[26];
queue<int> q;
bool vis[100000];
int rt[26][100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, Q; string a, b; char c;
	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++)
		cin >> w[i], mp[w[i]] = i, pre[w[i][0] - 'A'].push_back(i);
	while (M--) {
		cin >> a >> b;
		int ma = mp[a], mb = mp[b];
		adj[ma].push_back(mb), adj[mb].push_back(ma);
	}

	for (int i = 0; i < 26; i++)
		sort(pre[i].begin(), pre[i].end(), [&] (int x, int y) {
			return w[x] < w[y];
		});

	memset(rt, -1, sizeof(rt));
	for (int i = 0; i < 26; i++) {
		q = {}; memset(vis, false, sizeof(vis));
		for (int j : pre[i]) q.push(j), vis[j] = true, rt[i][j] = j;
		while (!q.empty()) {
			int cv = q.front(); q.pop();
			for (int j : adj[cv])
				if (!vis[j]) q.push(j), vis[j] = true, rt[i][j] = rt[i][cv];
		}
	}

	while (Q--) {
		cin >> a >> c; int ans = rt[c - 'A'][mp[a]];
		cout << (ans == -1 ? "-1" : w[ans]) << '\n';
	}
	return 0;
}
