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

int idxs[3], tmp[3];
ll dp[38][40][40][40], x[40], y[40];

#define add(x, y) x = ((x) + (y)) % MOD

ll area2(int a, int b, int c) {
	return abs(x[a] * (y[b] - y[c]) + x[b] * (y[c] - y[a]) + x[c] * (y[a] - y[b]));
}

bool inside(int a, int b, int c, int d) {
	return area2(a, b, d) + area2(a, c, d) + area2(b, c, d) == area2(a, b, c);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			for (int k = j + 1; k < N; k++)
				dp[0][i][j][k] = 6;
	for (int i = 0; i < N - 3; i++) {
		for (int a = 0; a < N; a++) {
			for (int b = a + 1; b < N; b++) {
				for (int c = b + 1; c < N; c++) {
					int cnt = 0;
					for (int j = 0; j < N; j++) {
						bool in = inside(a, b, c, j); cnt += in;
						if (in) continue;

						idxs[0] = a, idxs[1] = b, idxs[2] = c;
						for (int k = 0; k < 3; k++) {
							memcpy(tmp, idxs, 12), tmp[k] = j;
							if (tmp[0] > tmp[1]) swap(tmp[0], tmp[1]);
							if (tmp[1] > tmp[2]) swap(tmp[1], tmp[2]);
							if (tmp[0] > tmp[1]) swap(tmp[0], tmp[1]);
							if (inside(tmp[0], tmp[1], tmp[2], idxs[k]))
								add(dp[i + 1][tmp[0]][tmp[1]][tmp[2]], dp[i][a][b][c]);
						}
					}
					add(dp[i + 1][a][b][c], dp[i][a][b][c] * (cnt - i - 3));
				}
			}
		}
	}

	int ans = 0;
	for (int a = 0; a < N; a++)
		for (int b = a + 1; b < N; b++)
			for (int c = b + 1; c < N; c++)
				add(ans, dp[N - 3][a][b][c]);
	cout << ans << '\n';
	return 0;
}
