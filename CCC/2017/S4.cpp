// 11/17 partial

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

struct edge {
	int A, B, C; bool act;
	bool operator< (const edge &e) {
		return C < e.C || (C == e.C && act > e.act);
	}
};

edge edges[200000];
int par[100001], sz[100001], eidx;

void init(int N) { for (int i = 1; i <= N; i++) par[i] = i, sz[i] = 1; }
int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
bool join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return false;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u, sz[u] += sz[v];
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, D, A, B, C;
	cin >> N >> M >> D;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		edges[eidx++] = {A, B, C, i < N - 1};
	}

	init(N);
	sort(edges, edges + eidx);
	int days = 0, sz = 0;
	for (edge e : edges) {
		if (sz == N - 1) break;
		if (join(e.A, e.B)) {
			++sz;
			if (!e.act) ++days;
		}
	}

	cout << days << '\n';
	return 0;
}
