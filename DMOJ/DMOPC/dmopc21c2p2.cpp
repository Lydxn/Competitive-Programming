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

int p[301], a[301], w[301];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, x, y; char op;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) p[i] = w[i] = i;
	while (Q--) {
		cin >> op;
		if (op == 'B') {
			cin >> x >> y;
			w[p[x]] = y, w[p[y]] = x;
			swap(p[x], p[y]);
		} else if (op == 'E') {
			cin >> x >> y;
			p[w[x]] = y, p[w[y]] = x;
			swap(w[x], w[y]);
		} else {
			for (int i = 1; i <= N; i++) cin >> x, a[w[i]] = x;
			for (int i = 1; i <= N; i++) cout << a[i] << " \n"[i == N];
		}
	}
	return 0;
}
