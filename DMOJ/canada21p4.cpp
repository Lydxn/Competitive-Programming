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

int n, K, t[400000], x[400000], y[400000];

bool f(int sz) {
	ll mnx = x[0] - sz, mxx = x[0], mny = y[0] - sz, mxy = y[0];
	for (int i = 1; i < n; i++) {
		ll mnx2 = x[i] - sz, mxx2 = x[i], mny2 = y[i] - sz, mxy2 = y[i];
		ll d = 1LL * K * (t[i] - t[i - 1]);
		bool badx = false, bady = false;
		if (x[i] >= x[i - 1]) {
			if (mxx + d < mnx2) badx = true;
			mnx = mnx2, mxx = min(mxx2, mxx + d);
		} else {
			if (mnx - d > mxx2) badx = true;
			mxx = mxx2, mnx = max(mnx2, mnx - d);
		}
		if (y[i] >= y[i - 1]) {
			if (mxy + d < mny2) bady = true;
			mny = mny2, mxy = min(mxy2, mxy + d);
		} else {
			if (mny - d > mxy2) bady = true;
			mxy = mxy2, mny = max(mny2, mny - d);
		}
		if (badx || bady)
			return false;
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> K;
	for (int i = 0; i < n; i++) cin >> t[i] >> x[i] >> y[i];

	int l = 0, r = 1e9;
	while (l < r) {
		int m = (l + r) >> 1;
		if (f(m)) r = m;
		else l = m + 1;
	}
	cout << r << '\n';
	return 0;
}
