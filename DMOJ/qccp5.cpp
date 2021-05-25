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
int R, v[100001];
ld x[100001], y[100001], z[100001], da[100001], db[100001];
typedef pair<ld, int> pdi;
priority_queue<pdi, vector<pdi>, greater<pdi>> pq;

ld wtf(int i, int j) {
	return R * acos((x[i] * x[j] + y[i] * y[j] + z[i] * z[j]) / (1LL * R * R));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, T, K, a, b, k;
	cin >> N >> M >> R >> T >> K;
	for (int i = 1; i <= N; i++) da[i] = db[i] = INFL;
	while (K--) cin >> k, pq.emplace(0, k), da[k] = 0;
	for (int i = 1; i <= N; i++) cin >> v[i] >> x[i] >> y[i] >> z[i];
	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	while (!pq.empty()) {
		ld cw = pq.top().first; int cv = pq.top().second; pq.pop();
		if (cw > da[cv]) continue;
		for (int i : adj[cv]) {
			ld nd = da[cv] + wtf(cv, i);
			if (nd < da[i]) pq.emplace(da[i] = nd, i);
		}
	}
	pq.emplace(0, 1), db[1] = 0;
	while (!pq.empty()) {
		ld cw = pq.top().first; int cv = pq.top().second; pq.pop();
		if (cw > db[cv]) continue;
		for (int i : adj[cv]) {
			ld nd = db[cv] + wtf(cv, i);
			if (nd < db[i]) pq.emplace(db[i] = nd, i);
		}
	}
	int ans = -INF;
	for (int i = 1; i <= N; i++)
		if (da[i] + db[i] < T) ans = max(ans, v[i]);
	cout << (ans == -INF ? -1 : ans) << '\n';
	return 0;
}
