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

pii p[100001]; int pidx;
unordered_map<int, int> mp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, x;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		if (mp.count(x)) mp[x] = min(mp[x], i);
		else mp[x] = i;
	}
	for (auto i : mp) p[pidx++] = i;
	p[pidx] = {INT_MAX, INT_MAX};
	sort(p, p + pidx);
	while (Q--) {
		int w; cin >> w;
		int l = 0, r = N - 1;
		while (l < r) {
			int m = (l + r) >> 1;
			__uint128_t p1 = p[m].first, p2 = p[m + 1].first;
			if ((p1 * p1 + w) * p2 > (p2 * p2 + w) * p1) l = m + 1;
			else r = m;
		}
		__uint128_t p1 = p[l].first, p2 = p[l + 1].first;
		if ((p1 * p1 + w) * p2 == (p2 * p2 + w) * p1) cout << min(p[l].second, p[l + 1].second) << ' ';
		else cout << p[l].second << ' ';
	}
	cout << '\n';
	return 0;
}