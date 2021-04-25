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

	int N; double ans = 1; string a, b, c;
	cin >> N >> a >> b >> c;
	for (int i = 0; i < 2 * N; i += 2) {
		int p = 0;
		for (int j = i; j < i + 2; j++)
			for (int k = i; k < i + 2; k++)
				p += (a[j] == c[i] && b[k] == c[i + 1]) ||
					 (a[j] == c[i + 1] && b[k] == c[i]);
		ans *= p / 4.0;
	}
	cout << fixed << setprecision(6) << ans << '\n';
	return 0;
}
