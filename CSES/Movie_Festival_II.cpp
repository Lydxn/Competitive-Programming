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

pii a[200000];
multiset<int> m;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
	sort(a, a + n);
	for (int i = 0; i < k; i++) m.insert(0);
	for (int i = 0; i < n; i++) {
		auto it = m.upper_bound(a[i].second);
		if (it == m.begin()) continue;
		m.erase(--it), m.insert(a[i].first), ++ans;
	}
	cout << ans << '\n';
	return 0;
}
