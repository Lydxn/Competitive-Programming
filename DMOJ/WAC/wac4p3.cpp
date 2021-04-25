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

int N, S, sx[15], sy[15], vx[15], vy[15];
double dp[1 << 15][15];

double f(int i, double x, double y, double t) {
	double l = 0, r = 1e15, mid;
	for (int iter = 0; iter < 80; iter++) {
		mid = (l + r) / 2;
		double bx = sx[i] + vx[i] * (t + mid), by = sy[i] + vy[i] * (t + mid);
		if ((x - bx) * (x - bx) + (y - by) * (y - by) > mid * mid * S * S)
			l = mid;
		else
			r = mid;
	}
	return l;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> sx[i] >> sy[i] >> vx[i] >> vy[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (1 << N); j++)
			dp[j][i] = 1e15;
		dp[1 << i][i] = f(i, 0, 0, 0);
	}

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			if (!(i & (1 << j))) continue;
			for (int k = 0; k < N; k++) {
				if (i & (1 << k)) continue;
				double x = sx[j] + vx[j] * dp[i][j], y = sy[j] + vy[j] * dp[i][j];
				dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + f(k, x, y, dp[i][j]));
			}
		}
	}

	double ans = 1e15;
	for (int i = 0; i < N; i++)
		ans = min(ans, dp[(1 << N) - 1][i]);
	cout << fixed << setprecision(11) << ans << '\n';
	return 0;
}
