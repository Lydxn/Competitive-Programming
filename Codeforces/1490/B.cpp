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

	int t, n, a, c[3];
	cin >> t;
	while (t--) {
		cin >> n; memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++) cin >> a, ++c[a % 3];
		int ans = 0;
		while (!(c[0] == n / 3 && c[1] == c[0] && c[2] == c[1]))
			for (int i = 0; i < 3; i++)
				while (c[i] < n / 3 && c[(i + 2) % 3] > 0)
					++c[i], --c[(i + 2) % 3], ++ans;
		cout << ans << '\n';
	}
	return 0;
}
