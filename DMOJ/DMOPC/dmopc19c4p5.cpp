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

int d[300001], up[400001][20];
ll psa[300001], st[20][300001];

int query(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1);
	return psa[st[k][l]] < psa[st[k][r - (1 << k) + 1]] ? st[k][l] : st[k][r - (1 << k) + 1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, Q, l, r;
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++) cin >> d[i];
	for (int i = 1; i <= N; i++) psa[i] = psa[i - 1] + d[i];

	for (int i = 1; i <= N; i++) st[0][i] = i;
	for (int i = 0; i < 31 - __builtin_clz(N); i++)
		for (int j = 1; j + (1 << i) <= N; j++)
			st[i + 1][j] = psa[st[i][j]] < psa[st[i][j + (1 << i)]] ? st[i][j] : st[i][j + (1 << i)];

	for (int i = 1; i <= N; i++) {
		int l = i + 1, r = N, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (psa[query(i, mid)] >= psa[i]) l = mid + 1;
			else r = mid - 1;
		}
		up[i][0] = l;
	}

	for (int i = 1; i < 31 - __builtin_clz(N); i++)
		for (int j = 1; j <= N; j++)
			up[j][i] = up[up[j][i - 1]][i - 1];

	while (Q--) {
		cin >> l >> r;
		int mn = query(l, r);

		if (psa[mn] - psa[l - 1] >= -M) cout << psa[r] - psa[l - 1] + M << " 0\n";
		else {
			int li = l, ri = r, mid;
			while (li <= ri) {
				mid = (li + ri) >> 1;
				if (psa[query(li, mid)] - psa[l - 1] >= -M) li = mid + 1;
				else ri = mid - 1;
			}

			int cnt = 1;
			for (int i = 18; i >= 0; i--)
				if (up[li][i] <= r && up[li][i]) cnt += (1 << i), li = up[li][i];
			cout << psa[r] - psa[mn] << ' ' << cnt << '\n';
		}
	}
	return 0;
}
