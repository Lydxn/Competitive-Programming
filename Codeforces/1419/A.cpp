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
		bool b1 = false, b2 = false;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) b1 |= s[i] % 2;
			else b2 |= s[i] % 2 == 0;
		}
		cout << ((n % 2 && b1) || (n % 2 == 0 && !b2) ? 1 : 2) << '\n';
	}
	return 0;
}
