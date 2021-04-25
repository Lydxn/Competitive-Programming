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

struct segm {
	ll a, b;
	bool operator< (const segm &s) const { return b < s.b; }
} seg[200001];
ll dp[200001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll n; int k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) cin >> seg[i].a >> seg[i].b;
	sort(seg + 1, seg + k + 1);
	for (int i = 1; i <= k; i++) {
		segm s = {0, seg[i].a};
		dp[i] = max(dp[i - 1], dp[lower_bound(seg + 1, seg + k + 1, s) - seg - 1] + seg[i].b - seg[i].a + 1);
	}
	cout << n - dp[k] << '\n';
	return 0;
}
