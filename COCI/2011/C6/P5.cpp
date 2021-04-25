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

int a[257][257][257], p[257][257][257];

#define GET(r, g, b) p[r][g][b]
int get(int r1, int g1, int b1, int r2, int g2, int b2) {
	return GET(r2, g2, b2) - GET(r1 - 1, g2, b2) - GET(r2, g1 - 1, b2) - GET(r2, g2, b1 - 1)
	+ GET(r1 - 1, g1 - 1, b2) + GET(r1 - 1, g2, b1 - 1) + GET(r2, g1 - 1, b1 - 1) - GET(r1 - 1, g1 - 1, b1 - 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, R, G, B;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> R >> G >> B, ++a[R + 1][G + 1][B + 1];
	for (int i = 1; i <= 256; i++)
		for (int j = 1; j <= 256; j++)
			for (int k = 1; k <= 256; k++)
				p[i][j][k] = a[i][j][k] + p[i - 1][j][k] + p[i][j - 1][k] + p[i][j][k - 1]
				- p[i - 1][j - 1][k] - p[i - 1][j][k - 1] - p[i][j - 1][k - 1] + p[i - 1][j - 1][k - 1];

	int mn = INF, ri = -1, gi = -1, bi = -1;
	for (int i = 1; i <= 256; i++) {
		for (int j = 1; j <= 256; j++) {
			for (int k = 1; k <= 256; k++) {
				int l = 0, r = 256 - max(max(i, j), k), cur = INF;
				while (l < r) {
					int mid = (l + r) >> 1;
					if (get(i, j, k, i + mid, j + mid, k + mid) >= K) r = cur = mid;
					else l = mid + 1;
				}
				if (cur < mn) mn = l, ri = i, gi = j, bi = k;
			}
		}
	}
	
	cout << mn << '\n';
	for (int i = ri; i <= ri + mn; i++)
		for (int j = gi; j <= gi + mn; j++)
			for (int k = bi; k <= bi + mn; k++)
				while (a[i][j][k]-- && K) cout << i - 1 << ' ' << j - 1 << ' ' << k - 1 << '\n', --K;
	return 0;
}
