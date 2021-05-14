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

double dp[601];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	dp[0] = 1.0;
	for (int i = 1; i <= n; i++)
		for (int j = 6 * n; j >= 0; j++)
			for (int k = 1; k <= min(6, j); k++)
				dp[j] += dp[j - k] / 6.0;
	double ans = 0;
	for (int i = a; i <= b; i++) ans += dp[i];
	cout << fixed << setprecision(6) << ans << '\n';
	return 0;
}
