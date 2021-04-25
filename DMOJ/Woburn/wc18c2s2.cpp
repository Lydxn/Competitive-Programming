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

int O[200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, mn = 0, mx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> O[i];
	
	if (O[0] > 1) { cout << "-1\n"; return 0; }
	O[0] = 1;
	
	for (int i = N - 1, v = 0; i >= 0; i--) {
		if (v && O[i] && O[i] != v) { cout << "-1\n"; return 0; }
		if (O[i]) v = O[i];
		else if (v) O[i] = v;
		if (v) --v;
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (O[i]) {
			if (cnt) ++mn, mx += cnt + 1;
			else if (i && O[i] && O[i] != O[i - 1] + 1) ++mn, ++mx;
			cnt = 0;
		} else ++cnt;
	}
	cout << mn << ' ' << mx + cnt << '\n';
	return 0;
}
