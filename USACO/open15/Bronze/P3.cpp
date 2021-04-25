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

struct hay {
	int S, P;
	bool operator< (const hay &h) const { return P < h.P; }
} h[4000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("trapped.in", "r", stdin);
	freopen("trapped.out", "w", stdout);

	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> h[i].S >> h[i].P;
	sort(h, h + N);
	for (int i = 0; i < N - 1; i++) {
		int l = i, r = i + 1, x = h[r].P - h[l].P;
		while (l >= 0 && r < N) {
			int d = h[r].P - h[l].P;
			if (h[l].S < d) --l;
			else if (h[r].S < d) ++r;
			else break;
		}
		if (l >= 0 && r < N) ans += x;
	}
	cout << ans << '\n';
	return 0;
}