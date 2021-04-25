#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

const ll MX = 1LL << 31;
int x[1500], y[1500];
ll v0[1500], v1[1500];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

	for (int i = 0; i < N; i++) {
		int vidx = 0;
		for (int j = 0; j < N; j++) {
			if (j != i) {
				int dx = x[i] - x[j], dy = y[i] - y[j], gcd = __gcd(dx, dy);
				dx /= gcd, dy /= gcd;
				v0[vidx] = dx * MX + dy, v1[vidx++] = -dy * MX + dx;
			}
		}

		sort(v0, v0 + vidx);
		for (int j = 0; j < vidx; j++)
			ans += upper_bound(v0, v0 + vidx, v1[j]) - lower_bound(v0, v0 + vidx, v1[j]);
	}
	cout << ans << '\n';
	return 0;
}
