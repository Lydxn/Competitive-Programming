// testing vectorization

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

int a[2000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, x, y, z, prev = 0; char op;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> a[i];

	while (Q--) {
		cin >> op;
		if (op == 'I') {
			cin >> x >> y; x ^= prev, y ^= prev;
			memmove(a + x + 2, a + x + 1, (N++ - x) << 2);
			a[x + 1] = y;
		} else if (op == 'D') {
			cin >> x; x ^= prev;
			memmove(a + x, a + x + 1, (N-- - x) << 2);
		} else {
			cin >> x >> y >> z; x ^= prev, y ^= prev, z ^= prev;
			int ans = 0;
			for (int i = x; i <= y; i++) ans += a[i] == z;
			cout << ans << '\n';
			prev = ans;
		}
	}
	return 0;
}
