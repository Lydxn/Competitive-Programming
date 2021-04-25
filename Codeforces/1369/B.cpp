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

	int t, n; string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		int c0 = 0, l0 = n - 1;
		while (l0 >= 0 && s[l0] == '1') --l0;
		while (c0 < l0 && s[c0] == '0') ++c0;
		cout << string(l0 < 0 ? 0 : c0 + 1, '0') + string(n - l0 - 1, '1') << '\n';
	}
	return 0;
}
