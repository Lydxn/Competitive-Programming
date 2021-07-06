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

ll psa[200002], psb[200002], psc[200002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, x, l, r, a, b;
	cin >> N >> Q;
	while (Q--) {
		cin >> x >> l >> r >> a >> b;
		if (x == 0) {
			psb[l] += b, psb[r + 1] -= b;
			psb[r + 1] -= 1LL * b * (r - l + 1), psb[r + 2] += 1LL * b * (r - l + 1);
		} else {
			psc[r] += b, psc[l - 1] -= b;
			psc[l - 1] -= 1LL * b * (r - l + 1), psc[l - 2] += 1LL * b * (r - l + 1);
		}
		psa[l] += a, psa[r + 1] -= a;
	}
	for (int i = 1; i <= N; i++) psa[i] += psa[i - 1];
	for (int i = 1; i <= N; i++) psb[i] += psb[i - 1];
	for (int i = 1; i <= N; i++) psb[i] += psb[i - 1];
	for (int i = N; i; i--) psc[i] += psc[i + 1];
	for (int i = N; i; i--) psc[i] += psc[i + 1];
	for (int i = 1; i <= N; i++) cout << psa[i] + psb[i] + psc[i] << '\n';
	return 0;
}
