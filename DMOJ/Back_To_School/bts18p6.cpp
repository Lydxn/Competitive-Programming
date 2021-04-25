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

ll da[100001], db[100001], dc[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, T; ll L, R, a, b, c;
	cin >> N >> T;
	while (N--) {
		cin >> L >> R >> a >> b >> c;
		ll na = a, nb = -2 * a * L + b, nc = a * L * L - b * L + c;
		da[L] += na, da[R + 1] -= na;
		db[L] += nb, db[R + 1] -= nb;
		dc[L] += nc, dc[R + 1] -= nc;
	}

	for (int i = 1; i <= T; i++) {
		da[i] += da[i - 1], db[i] += db[i - 1], dc[i] += dc[i - 1];
		cout << da[i] * i * i + db[i] * i + dc[i] << ' ';
	}
	cout << '\n';
	return 0;
}
