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

bool row[100001], col[100001];
unordered_map<ll, bool> rc;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, op, r, c;
	cin >> N >> Q;
	while (Q--) {
		cin >> op >> r >> c;
		if (op == 1) row[r] ^= true, col[c] ^= true, rc[(ll) r << 20 | c] ^= true;
		else cout << (row[r] ^ col[c] ^ rc[(ll) r << 20 | c]) << '\n';
	}
	return 0;
}
