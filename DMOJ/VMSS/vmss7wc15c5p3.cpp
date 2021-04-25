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

int BIT[2001][2001];

void update(int r, int c, int x) {
	for (int idx = r + c; c <= idx; c += c & -c) BIT[idx][c] = (BIT[idx][c] + x) % MOD;
}

int query(int r, int c) {
	int res = 0;
	for (int idx = r + c; c; c -= c & -c) res = (res + BIT[idx][c]) % MOD;
	return res;
}

int query(int r, int c, int x) {
	return (query(r - x, c + x) - query(r + 1, c - 1) + MOD) % MOD;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, op, r, c, x, ans = 0;
	cin >> N;
	while (N--) {
		cin >> op >> r >> c >> x;
		if (op == 1) update(r, c, x);
		else ans = (ans + query(r, c, x)) % MOD;
	}
	cout << ans << '\n';
	return 0;
}
