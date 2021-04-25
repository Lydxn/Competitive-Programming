#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize "Ofast"

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

ll a[200000];
int st[18][200000];

int query(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1);
	return a[st[k][l]] < a[st[k][r - (1 << k) + 1]] ? st[k][l] : st[k][r - (1 << k) + 1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q, l, r; ll v;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i], st[0][i] = i;
	for (int i = 0; i < 31 - __builtin_clz(n); i++)
		for (int j = 0; j + (1 << i) < n; j++)
			st[i + 1][j] = a[st[i][j]] < a[st[i][j + (1 << i)]] ? st[i][j] : st[i][j + (1 << i)];

	while (q--) {
		cin >> v >> l >> r; --l, --r;
		while (l <= r) {
			int li = l, ri = r, mid;
			while (li <= ri) {
				mid = (li + ri) >> 1;
				if (a[query(l, mid)] > v) li = mid + 1;
				else ri = mid - 1;
			}

			if (li > r) break;
			v %= a[l = li];
		}
		cout << v << '\n';
	}
	return 0;
}
