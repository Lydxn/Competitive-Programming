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

	int D, Q, d, q; int mnd = INT_MAX, mnq = INT_MAX, mxd = INT_MIN, mxq = INT_MIN;
	cin >> D;
	for (int i = 0; i < D; i++) cin >> d, mnd = min(mnd, d), mxd = max(mxd, d);
	cin >> Q;
	for (int i = 0; i < Q; i++) cin >> q, mnq = min(mnq, q), mxq = max(mxq, q);

	cout << (10.0 / mxd > 25.0 / mnq ? "Dimes are better" : 10.0 / mnd < 25.0 / mxq ? "Quarters are better" : "Neither coin is better") << '\n';
	return 0;

}
