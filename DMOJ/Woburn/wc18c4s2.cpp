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

pii a[3001];
ll dp[3001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, H;
	cin >> N >> H;
	for (int i = 1; i <= N; i++) cin >> a[i].first >> a[i].second;
	sort(a + 1, a + N + 1);
	memset(dp, INFL, sizeof(dp)); dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		int mx = a[i].second;
		for (int j = i - 1; j >= 0; j--) {
			int x = 2 * (a[i].first - a[j + 1].first);
			dp[i] = min(dp[i], dp[j] + a[i].first - a[j].first + x + max(0, mx - x));
			mx = max(mx, a[j].second);
		}
	}
	cout << dp[N] + H - a[N].first << '\n';
	return 0;
}
