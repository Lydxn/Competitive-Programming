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

unordered_map<string, int> mp;
vector<int> adj[1000], radj[1000];
bool vis1[1000], vis2[1000], vis3[1000];
int midx;

bool dfs2(int rep, int cur) {
	if (vis2[cur]) return cur == rep;
	vis2[cur] = true;
	bool res = false;
	for (int i : adj[cur]) res |= dfs2(rep, i);
	return res;
}

bool dfs1(int cur) {
	if (vis1[cur]) return false;
	vis1[cur] = true;
	memset(vis2, false, sizeof(vis2));
	bool res = dfs2(cur, cur);
	for (int i : adj[cur]) res |= dfs1(i);
	for (int i : radj[cur]) res |= dfs1(i);
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, p; string n, m;
	cin >> T;
	while (T--) {
		cin >> N;
		mp.clear(), midx = 0;
		for (int i = 0; i < N; i++) adj[i].clear(), radj[i].clear();
		memset(vis1, false, sizeof(vis1)); memset(vis2, false, sizeof(vis2));
		
		for (int i = 0; i < N; i++) {
			cin >> n >> p;
			if (!mp.count(n)) mp[n] = midx++;
			while (p--) {
				cin >> m;
				if (!mp.count(m)) mp[m] = midx++;
				adj[mp[n]].push_back(mp[m]);
				radj[mp[m]].push_back(mp[n]);
			}
		}
		cout << (dfs1(mp["Jim-Bob"]) ? "Redneck" : "Not a redneck") << '\n';
	}
	return 0;
}
