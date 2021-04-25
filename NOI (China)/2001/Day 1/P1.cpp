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

int par[150001], sz[150001];

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
void join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return;
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v], par[v] = u;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, D, X, Y, ans = 0;
	cin >> N >> K;
	for (int i = 1; i <= N * 3; i++) par[i] = i, sz[i] = 1;
	while (K--) {
		cin >> D >> X >> Y;
		if (X > N || Y > N || (D == 2 && X == Y)) { ++ans; continue; }
		if (D == 1) {
			if (find(X) == find(Y + N) || find(X) == find(Y + N + N)) ++ans;
			else join(X, Y), join(X + N, Y + N), join(X + N + N, Y + N + N);
		} else {
			if (find(X) == find(Y) || find(X) == find(Y + N + N)) ++ans;
			else join(X, Y + N), join(X + N, Y + N + N), join(X + N + N, Y);
		}
	}
	cout << ans << '\n';
	return 0;
}
