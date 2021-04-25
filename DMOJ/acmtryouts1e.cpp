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

ll dp[201][201];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, M, A, B;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
		for (int i = 1; i <= N; i++) {
			cin >> A >> B;
			for (int j = A; j <= B; j++)
				for (int k = 0; k <= M; k++)
					if (k - j >= 0)
						dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % MOD;
		}
		cout << dp[N][M] << '\n';
	}
	return 0;
}
