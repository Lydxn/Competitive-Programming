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

	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n; int s = 0, cnt1 = 0, cnt2 = 0;
		while (n--) cin >> x, s += x, (x == 1 ? cnt1 : cnt2)++;
		cout << (s % 2 == 0 && (cnt1 >= 2 || cnt2 % 2 == 0) ? "YES" : "NO") << '\n';
	}
	return 0;
}
