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

	int T; ull A, B;
	cin >> T;
	while (T--) {
		cin >> A >> B;
		ull g = __gcd(A, B);
		assert(g > 0);
		A /= g, B /= g;
		ull c = B;
		while (c % 2 == 0) c /= 2;
		while (c % 5 == 0) c /= 5;
		if (c == 1) {
			int ans = 0;
			while (A % B) ++ans, A = A * 10 % B;
			cout << ans << '\n';
		} else cout << "-1\n";
	}
	return 0;
}
