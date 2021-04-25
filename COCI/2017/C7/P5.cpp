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

int M, A[501], dp1[501][501], dp2[501][501];
vector<int> adj[501];

void dfs(int cur, int prev) {
	dp1[cur][1] = dp2[cur][1] = A[cur];
	for (int i : adj[cur]) {
		if (i == prev) continue;
		dfs(i, cur);
		for (int j = M; j >= 0; j--) {
			for (int k = 0; k <= j; k++) {
				if (j - k - 2 >= 0) {
					dp2[cur][j] = max(dp2[cur][j], dp2[i][k] + dp2[cur][j - k - 2]);
					dp1[cur][j] = max(dp1[cur][j], dp2[i][k] + dp1[cur][j - k - 2]);
				}
				if (j - k - 1 >= 0)
					dp1[cur][j] = max(dp1[cur][j], dp1[i][k] + dp2[cur][j - k - 1]);
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, U, V;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		adj[U].push_back(V), adj[V].push_back(U);
	}
	dfs(1, 0);
	cout << dp1[1][M] << '\n';
	return 0;
}
