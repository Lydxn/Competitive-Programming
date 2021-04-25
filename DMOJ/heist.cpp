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

int V[100001], dq[100001], fidx, bidx;
ll dp[100031], psa[100031];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, K, x; ll ans;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		if (N == K) {
			ans = 0;
			while (N--) cin >> x, ans += max(0, x);
			cout << ans << '\n';
			continue;
		}

		for (int i = 1; i <= N; i++) cin >> V[i], V[i] = max(0, V[i]);
		for (int i = 1; i <= K; i++) V[N + i] = V[i];
		for (int i = 1; i <= N + K; i++) psa[i] = psa[i - 1] + V[i];

		ans = 0;
		for (int x = 0; x <= K; x++) {
			fidx = bidx = 0, dq[0] = 0;
			for (int i = 1; i < N; i++) {
				if (dq[fidx] < i - K - 1) ++fidx;
				dp[i] = dp[dq[fidx]] + V[i + x];
				while (fidx <= bidx && dp[dq[bidx]] >= dp[i]) --bidx;
				dq[++bidx] = i;
			}

			ll mn = INFL;
			for (int i = N - K - 1; i < N; i++) mn = min(mn, dp[i]);
			ans = max(ans, psa[N + x - 1] - psa[x] - mn);
		}
		cout << ans << '\n';
	}
	return 0;
}
