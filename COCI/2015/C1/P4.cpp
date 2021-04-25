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

unordered_map<ll, int> mp;
unordered_map<int, int> xr, xc, cntr, cntc;
int N; ll ans;

void update(int r, int c, int x) {
	ans -= N - cntr[xc[c]], ans -= N - cntc[xr[r]];
	--cntr[xr[r]], --cntc[xc[c]];
	xr[r] ^= x, xc[c] ^= x;
	++cntr[xr[r]], ++cntc[xc[c]];
	ans += N - cntr[xc[c]], ans += N - cntc[xr[r]];
	mp[1LL * r << 31LL | c] ^= x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K, P, R, C, X, R1, C1, R2, C2;
	cin >> N >> K >> P; cntr[0] = cntc[0] = N;
	while (K--) {
		cin >> R >> C >> X;
		update(R, C, X);
	}

	while (P--) {
		cin >> R1 >> C1 >> R2 >> C2;
		X = mp[1LL * R1 << 31LL | C1];
		update(R1, C1, X), update(R2, C2, X);
		cout << ans << '\n';
	}
	return 0;
}
