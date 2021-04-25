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

int o[100000], oidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("socdist1.in", "r", stdin);
	freopen("socdist1.out", "w", stdout);

	int N; char b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> b;
		if (b == '1') ++oidx;
		else ++o[oidx];
	}

	if (oidx == 0) { cout << N - 1 << '\n'; return 0; }

	int mn = INF, mx3 = 0, mx1 = 0, mx2 = 0;
	for (int i = 0; i <= oidx; i++) {
		int c;
		if (i != 0 && i != oidx)
			mx3 = max(mx3, (o[i] + 1) / 3), mn = min(mn, o[i] + 1), c = (o[i] + 1) / 2;
		else
			mx3 = max(mx3, o[i] / 2), c = o[i];
		if (c > mx1) mx2 = mx1, mx1 = c;
		else if (c > mx2) mx2 = c;
	}
	cout << min(mn, max(mx2, mx3)) << '\n';
	return 0;
}
