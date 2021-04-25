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

int dp[1 << 20], p[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, t, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> K; int msk = 0;
		while (K--) cin >> t, msk |= 1 << (t - 1);
		++dp[msk];
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < 1 << M; j++)
			if (!(j & (1 << i))) dp[j | (1 << i)] += dp[j];
	p[0] = 1;
	for (int i = 1; i <= N; i++) p[i] = (p[i - 1] << 1) % MOD;
	for (int i = 0; i < 1 << M; i++) {
		if ((M - __builtin_popcount(i)) & 1) ans = (ans - p[dp[i]] + MOD) % MOD;
		else ans = (ans + p[dp[i]]) % MOD;
	}
	cout << ans << '\n';
	return 0;
}
