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

int F[100001], dp[4][4][4][4][2];

int V(int a, int b, int c) {
	return (a == 0 || b == 0 || c == 0) + (a == 1 || b == 1 || c == 1) + (a == 2 || b == 2 || c == 2);
}

void M(int &a, int b) {
	a = max(a, b);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; char c;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> c, F[i] = c == 'M' ? 0 : c == 'F' ? 1 : 2;
	for (int i = 0; i < N; i++) {
		for (int l1 = 0; l1 < 3; l1++) {
			for (int l2 = 0; l2 < 3; l2++) {
				for (int r1 = 0; r1 < 3; r1++) {
					for (int r2 = 0; r2 < 3; r2++) {
						M(dp[F[i]][l1][r1][r2][(i & 1) ^ 1], dp[l1][l2][r1][r2][i & 1] + V(F[i], l1, l2));
						M(dp[l1][l2][F[i]][r1][(i & 1) ^ 1], dp[l1][l2][r1][r2][i & 1] + V(F[i], r1, r2));
					}
				}
			}
		}
	}

	int ans = 0;
	for (int l1 = 0; l1 < 3; l1++)
		for (int l2 = 0; l2 < 3; l2++)
			for (int r1 = 0; r1 < 3; r1++)
				for (int r2 = 0; r2 < 3; r2++)
					ans = max(ans, dp[l1][l2][r1][r2][N & 1]);
	cout << ans - 6 << '\n';
	return 0;
}
