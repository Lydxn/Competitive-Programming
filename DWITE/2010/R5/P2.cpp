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

bool r[31001], c[31001];

void solve() {
	int R, C, Ro, X, Y, tr = 0, tc = 0;
	cin >> R >> C >> Ro;

	memset(r, false, sizeof(r));
	memset(c, false, sizeof(c));
	while (Ro--) cin >> X >> Y, r[X] = c[Y] = true;
	for (int i = 1; i <= R; i++) tr += r[i];
	for (int i = 1; i <= C; i++) tc += c[i];
	cout << R * C - (tr * C + tc * R - tr * tc) << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 5; _++) solve();
	return 0;
}
