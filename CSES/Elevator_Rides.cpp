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

pii dp[1 << 20];
int w[20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 1; i < 1 << n; i++) dp[i] = {INF, 0};
	dp[0] = {1, 0};
	
	for (int i = 0; i < 1 << n; i++) {
		for (int j = 0; j < n; j++) {
			if (!(i & (1 << j))) {
				pii c = dp[i];
				pii best = c.second + w[j] > x ? make_pair(c.first + 1, w[j]) : make_pair(c.first, c.second + w[j]);
				dp[i | (1 << j)] = min(dp[i | (1 << j)], best);
			}
		}
	}
	cout << dp[(1 << n) - 1].first << '\n';
	return 0;
}
