#pragma GCC optimize "Ofast"
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

int a[1001][1001], lr[1000], lc[1000], sr[1000], sc[1000];
bool ar[1000], alt[1000];

int f(int r1, int c1, int r2, int c2) {
	return a[r2][c2] - a[r1 - 1][c2] - a[r2][c1 - 1] + a[r1 - 1][c1 - 1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, C, L, W, H, ansr = -1, ansc = -1, mx = 0;
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> a[i][j], a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
	cin >> L >> W >> H;
	for (int i = 0; i < H; i++) cin >> lr[i] >> lc[i] >> sr[i] >> sc[i] >> ar[i] >> alt[i];
	for (int i = 1; i <= R - L + 1; i++) {
		for (int j = 1; j <= C - W + 1; j++) {
			int cur = 0;
			for (int k = 0; k < H; k++) {
				int cr = i + lr[k] - 1, cc = j + lc[k] - 1;
				int p1 = f(cr, cc, cr + sr[k] - 1, cc + sc[k] - 1), p2;
				if (ar[k])
					p2 = f(cr + sr[k], cc, cr + 2 * sr[k] - 1, cc + sc[k] - 1);
				else
					p2 = f(cr, cc + sc[k], cr + sr[k] - 1, cc + 2 * sc[k] - 1);
				cur += (p1 >= p2) == alt[k];
				if (cur + H - k - 1 <= mx) goto nxt;
			}
			if (cur > mx) mx = cur, ansr = i, ansc = j;
			nxt:;
		}
	}
	cout << ansr << ' ' << ansc << '\n';
	return 0;
}