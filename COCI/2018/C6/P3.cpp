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

int P[501], B[501], dp[501][501];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> P[i];
	for (int i = 0; i <= M; i++) cin >> B[i];
	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= K; j++)
			for (int k = 0; k <= j; k++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + B[P[i] + k]);
	cout << dp[N][K] << '\n';
	return 0;
}
