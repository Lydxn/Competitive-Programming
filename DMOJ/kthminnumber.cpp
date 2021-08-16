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

const int MN = 200000;
int a[MN], b[MN], ind[MN], rev[MN], nxt[MN], mid[18], cnt[18][(MN >> 5) + 1];
unsigned wm[18][(MN + 31) >> 5];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, l, r, k, lans = 0;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> a[i], ind[i] = i;
	sort(ind, ind + N, [&] (int &x, int &y) { return a[x] < a[y]; });
	for (int i = 0, j = 0; i < N; i++)
		j += i && a[ind[i]] != a[ind[i - 1]], b[ind[i]] = j, rev[j] = a[ind[i]];
	for (int i = 17; i >= 0; i--) {
		for (int j = 0; j < N; j++)
			mid[i] += !((b[j] >> i) & 1);
		for (int j = 0, li = 0, ri = mid[i]; j < N; j++) {
			if ((b[j] >> i) & 1)
				nxt[ri++] = b[j], wm[i][j >> 5] |= 1U << (j & 31);
			else
				nxt[li++] = b[j];
		}
		for (int j = 1; j <= N >> 5; j++)
			cnt[i][j] = cnt[i][j - 1] + __builtin_popcount(wm[i][j - 1]);
		memcpy(b, nxt, N << 2);
	}
	while (Q--) {
		cin >> l >> r >> k; l ^= lans, r ^= lans, k ^= lans; l--;
		int ans = 0;
		for (int i = 17; i >= 0; i--) {
			int cl = l - cnt[i][l >> 5] - __builtin_popcount(wm[i][l >> 5] & ((1U << (l & 31)) - 1));
			int cr = r - cnt[i][r >> 5] - __builtin_popcount(wm[i][r >> 5] & ((1U << (r & 31)) - 1));
			int c = cr - cl;
			if (c >= k)
				l = cl, r = cr;
			else
				k -= c, l += mid[i] - cl, r += mid[i] - cr, ans |= 1 << i;
		}
		cout << (lans = rev[ans]) << '\n';
	}
	return 0;
}