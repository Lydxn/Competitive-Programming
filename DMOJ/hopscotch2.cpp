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

const int MAXN = 8388610;
ll dp[MAXN], a[MAXN];
int dq[MAXN], p[MAXN], ans[MAXN], aidx, fidx, bidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N + 1; i++) {
		while (fidx <= bidx && i - dq[fidx] > K) ++fidx;
		dp[i] = dp[dq[fidx]] + a[i], p[i] = dq[fidx];
		while (fidx <= bidx && dp[dq[bidx]] >= dp[i]) --bidx;
		dq[++bidx] = i;
	}
	
	cout << dp[++N] << '\n';
	for (; p[N]; ) ans[aidx++] = N = p[N];
	while (aidx--) cout << ans[aidx] << ' ';
	cout << '\n';
	return 0;
}
