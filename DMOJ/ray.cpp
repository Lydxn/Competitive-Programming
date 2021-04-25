#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize "Ofast"

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

ll P[30][100][100], dp[100], dp2[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, Q, a, b, w, k;
	cin >> N >> M >> Q;
	memset(P[0], INFL, sizeof(P[0]));
	while (M--) cin >> a >> b >> w, P[0][a - 1][b - 1] = min(P[0][a - 1][b - 1], 1LL * w);

	for (int p = 0; p < 29; p++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ll s = INFL;
				for (int k = 0; k < N; k++)
					s = min(s, P[p][i][k] + P[p][k][j]);
				P[p + 1][i][j] = s;
			}
		}
	}

	while (Q--) {
		cin >> a >> b >> k;
		memset(dp, INFL, sizeof(dp)); dp[a - 1] = 0;
		for (int p = 0; (1 << p) <= k; p++) {
			if (!(k & (1 << p))) continue;
			memset(dp2, INFL, sizeof(dp2));
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					dp2[j] = min(dp2[j], dp[i] + P[p][i][j]);
			memcpy(dp, dp2, sizeof(dp2));
		}
		cout << (dp[b - 1] == INFL ? -1 : dp[b - 1]) << '\n';
	}
	return 0;
}
