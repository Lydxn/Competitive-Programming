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

int st0[16][500000], st1[16][500000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b;
	cin >> N >> Q;
	for (int i = 0, x; i < N; i++) cin >> x, st0[0][i] = st1[0][i] = x;

	for (int j = 0; j < __lg(N); j++)
		for (int i = 0; i + (1 << j) < N; i++)
			st0[j + 1][i] = min(st0[j][i], st0[j][i + (1 << j)]),
			st1[j + 1][i] = max(st1[j][i], st1[j][i + (1 << j)]);

	while (Q--) {
		cin >> a >> b; --a, --b;
		int k = __lg(b - a + 1);
		cout << max(st1[k][a], st1[k][b - (1 << k) + 1]) - min(st0[k][a], st0[k][b - (1 << k) + 1]) << '\n';
	}
	return 0;
}
