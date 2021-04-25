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

int T[200001], dist[200001];
vector<pii> adj[200001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
map<int, vector<int>> mp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, A, B, C;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> T[i];
	while (M--) {
		cin >> A >> B >> C;
		adj[A].emplace_back(B, C), adj[B].emplace_back(A, C);
	}

	memset(dist, INF, sizeof(dist)); dist[1] = 0;
	pq.emplace(0, 1);
	while (!pq.empty()) {
		pii cv = pq.top(); pq.pop();
		for (auto i : adj[cv.second]) {
			int nv = max(cv.first, i.second);
			if (nv < dist[i.first])
				pq.emplace(dist[i.first] = nv, i.first);
		}
	}

	for (int i = 1; i <= N; i++)
		if (dist[i] != INF) mp[dist[i]].push_back(i);
	
	ll ans = 0; int lvl = 1, mt = INF;
	for (auto i : mp) {
		int d = i.first;
		ans += 1LL * max(0, d - lvl) * mt;
		for (int j : i.second) {
			if (j == N) { cout << ans << '\n'; return 0; }
			mt = min(mt, T[j]);
		}
		lvl = max(lvl, d);
	}
	cout << "-1\n";
}
