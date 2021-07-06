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

int a[2000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, [&] (int &x, int &y) { return x % 2 < y % 2; });
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0) ans += n - i - 1;
			else
				for (int j = i + 1; j < n; j++)
					ans += __gcd(a[i], a[j]) > 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
