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

unsigned dp1[10002], dp2[10002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, h;
	cin >> N >> h;
	dp1[0] = h <= 0;
	for (int i = 2; i <= N; i++) {
		cin >> h;
		if (h == -1) {
			dp2[0] = (dp1[0] + dp1[1]) % MOD;
			for (int j = 1; j <= min(i, N - i); j++)
				dp2[j] = (dp1[j - 1] + dp1[j] + dp1[j + 1]) % MOD;
		} else memset(dp2, 0, (N + 1) << 2), dp2[h] = ((h ? dp1[h - 1] : 0) + dp1[h] + dp1[h + 1]) % MOD;
		memcpy(dp1, dp2, (N + 1) << 2);
	}
	cout << dp1[0] << '\n';
	return 0;
}