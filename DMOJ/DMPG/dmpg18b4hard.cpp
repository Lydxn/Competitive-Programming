// same as dmpg18b4

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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, X, x, mx = 0, s = 0, ans = -1; double d = INF;
	cin >> N >> M >> X;
	for (int i = 0; i < N; i++) cin >> x, mx = max(mx, x), s += x;
	while (M--) {
		cin >> x;
		if (x < mx || s * 2 < N * x) continue;
		double cur = abs(100.0 * s / x / N - X);
		if (d > cur) d = cur, ans = x;
		else if (d == cur && ans < x) ans = x;
	}
	if (ans == -1) cout << "Shimnanigans have failed\n";
	else cout << ans << '\n';
	return 0;
}
