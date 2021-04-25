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

int dp[1001][1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int D, I, R; string A, B;
	cin >> D >> I >> R >> A >> B;
	int sa = A.size(), sb = B.size();

	for (int i = 0; i <= sa; i++) dp[i][0] = i * D;
	for (int i = 0; i <= sb; i++) dp[0][i] = i * I;
	for (int i = 1; i <= sa; i++) {
		for (int j = 1; j <= sb; j++) {
			if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(dp[i - 1][j] + D, min(dp[i][j - 1] + I, dp[i - 1][j - 1] + R));
		}
	}
	cout << dp[sa][sb] << '\n';
	return 0;
}
