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

int l[100001], r[100001], mn[100001], mx[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
	for (int i = n; i; i--) {
		int lv = l[i] == -1 ? 0 : l[i], rv = r[i] == -1 ? 0 : r[i];
		mn[i] = min(mn[lv], mn[rv]) + 1;
		mx[i] = max(mx[lv], mx[rv]) + 1;
		if (mn[lv] < mx[rv]) ++ans;
		if (mx[i] - mn[i] > 1 || (mn[lv] < mx[lv] && mn[rv] < mx[rv]))
			{ cout << "-1\n"; return 0; }
	}
	cout << ans << '\n';
	return 0;
}
