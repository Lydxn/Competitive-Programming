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

	ll n1, d1, n2, d2;
	while (cin >> n1 >> d1 >> n2 >> d2) {
		int d = d1 * d2 / __gcd(d1, d2), n = n1 * d / d1 + n2 * d / d2;
		int g = __gcd(n, d); n /= g, d /= g;
		if (d == 1) cout << n << '\n';
		else cout << n << ' ' << d << '\n';
	}
	return 0;
}
