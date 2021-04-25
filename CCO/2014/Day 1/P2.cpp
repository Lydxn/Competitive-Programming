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

int N, X[100001], Y[100001], L[100001], C[100001], dist[100001], rdist[100001];
pii tot[100001];
vector<int> adj[100001], radj[100001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int s, vector<int> A[], int D[], int E[]) {
	memset(D, INF, (N + 1) << 2);
	pq.emplace(0, s), D[s] = 0;
	while (!pq.empty()) {
		int cw = pq.top().first, cv = pq.top().second; pq.pop();
		if (cw > D[cv]) continue;
		for (int i : A[cv])
			if (D[cv] + L[i] < D[E[i]])
				pq.emplace(D[E[i]] = D[cv] + L[i], E[i]);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, A, B, Q, D;
	cin >> N >> M >> A >> B;
	for (int i = 1; i <= M; i++) {
		cin >> X[i] >> Y[i] >> L[i] >> C[i];
		adj[X[i]].push_back(i), radj[Y[i]].push_back(i);
	}

	dijkstra(A, adj, dist, Y), dijkstra(B, radj, rdist, X);
	for (int i = 1; i <= M; i++) tot[i] = {dist[X[i]] + L[i] + rdist[Y[i]], C[i]};
	sort(tot + 1, tot + M + 1);
	for (int i = 1; i <= M; i++) tot[i].second += tot[i - 1].second;

	cin >> Q;
	while (Q--) {
		cin >> D;
		cout << tot[upper_bound(tot + 1, tot + M + 1, make_pair(D, INF)) - tot - 1].second << '\n';
	}
	return 0;
}
