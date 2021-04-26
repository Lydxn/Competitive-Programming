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

int p[20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n; ll sum = 0, ans = INF;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i], sum += p[i];

	for (int i = 0; i < 1 << n; i++) {
		ll s = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) s += p[j];
		ans = min(ans, abs(2 * s - sum));
	}
	cout << ans << '\n';
	return 0;
}