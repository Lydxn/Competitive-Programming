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

int n;
ll bit[200001];

void update(int i, int v) {
	for (; i <= n; i += i & -i) bit[i] += v;
}

ll query(int i) {
	ll res = 0;
	for (; i; i -= i & -i) res += bit[i];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int q, x, op, a, b, u, k;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> x, update(i, x), update(i + 1, -x);
	while (q--) {
		cin >> op;
		if (op == 1) cin >> a >> b >> u, update(a, u), update(b + 1, -u);
		else cin >> k, cout << query(k) << '\n';
	}
	return 0;
}
