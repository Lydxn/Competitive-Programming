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

ll dp[102][102], x[102][102];

void matmul(ll A[102][102], ll B[102][102], int N) {
	ll res[102][102] = {0};
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N; j++)
				res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
		}
	}
	memcpy(A, res, sizeof(res));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N, K, T, C;
	cin >> N >> K >> T >> C;

	dp[0][0] = 1, dp[0][T] = K;
	for (int i = 1; i <= T; i++)
		dp[i][i - 1] = 1;
	dp[T + 1][0] = K, dp[T + 1][T] = -K, dp[T + 1][T + 1] = 1;

	for (int i = 0; i <= T + 1; i++)
		x[i][i] = 1;

	--N;
	while (N) {
		if (N & 1) matmul(x, dp, T + 2);
		matmul(dp, dp, T + 2), N >>= 1;
	}

	cout << (x[0][0] * 2 + x[T + 1][0]) * C % MOD << '\n';
	return 0;
}
