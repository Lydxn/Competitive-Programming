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

ll dp[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, C, a, b, c, d;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		for (int j = a + c; j <= C; j++) dp[j] = max(dp[j], dp[j - a - c] + b + d);
		for (int j = C; j >= a; j--) dp[j] = max(dp[j], dp[j - a] + b);
		for (int j = C; j >= c; j--) dp[j] = max(dp[j], dp[j - c] + d);
	}
	cout << dp[C] << '\n';
	return 0;
}
