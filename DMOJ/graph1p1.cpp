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

int dp[100][101];
bool adj[100][100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> adj[i][j];

	for (int i = 0; i < N; i++) dp[i][0] = 1;
	for (int i = 1; i <= K; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (adj[j][k])
					dp[k][i] += dp[j][i - 1];

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += dp[i][K];
	cout << ans << '\n';
	return 0;
}
