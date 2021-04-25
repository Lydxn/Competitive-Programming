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

int adj[101][101], col[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

	int N, M, a, b;
	cin >> N >> M;
	while (M--) cin >> a >> b, adj[a][b] = adj[b][a] = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 4; j++) {
			bool good = true;
			for (int k = 1; k <= N; k++)
				if (adj[i][k] && col[k] == j) good = false;
			if (good) { cout << j, col[i] = j; break; }
		}
	}
	return 0;
}
