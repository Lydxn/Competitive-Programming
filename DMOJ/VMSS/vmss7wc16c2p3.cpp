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

// reduction LCS -> LIS
int dp[1000001], idx[1000001], C[1000000], cidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, A, B;
	cin >> N;
	memset(idx, -1, sizeof(idx));
	for (int i = 0; i < N; i++) cin >> A, idx[A] = i;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> B;
		if (idx[B] != -1) C[cidx++] = idx[B];
	}

	int ans = 0;
	for (int i = 0; i < cidx; i++) {
		int x = upper_bound(dp, dp + ans, C[i]) - dp;
		dp[x] = C[i];
		if (x == ans) ++ans;
	}
	cout << ans << '\n';
	return 0;
}
