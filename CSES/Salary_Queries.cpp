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

int p[200001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q, a, b; char op; ordered_set<pii> os;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> p[i], os.insert({p[i], i});
	while (q--) {
		cin >> op >> a >> b;
		if (op == '!') os.erase({p[a], a}), os.insert({p[a] = b, a});
		else cout << os.order_of_key({b, INF}) - os.order_of_key({a, -INF}) << '\n';
	}
	return 0;
}
