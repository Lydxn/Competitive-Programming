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

int x[1000001], y[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, op, w, mnx = INF, mny = INF, mxx = 0, mxy = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> x[i], mnx = min(mnx, x[i]), mxx = max(mxx, x[i]);
	for (int i = 1; i <= N; i++) cin >> y[i], mny = min(mny, y[i]), mxy = max(mxy, y[i]);
	cin >> Q;
	while (Q--) {
		cin >> op >> w;
		if (op == 1) cout << max(mxy, x[w]) << '\n';
		else if (op == 2) cout << max(mny, x[w]) << '\n';
		else if (op == 3) cout << max(mxx, y[w]) << '\n';
		else cout << max(mnx, y[w]) << '\n';
	}
	return 0;
}
