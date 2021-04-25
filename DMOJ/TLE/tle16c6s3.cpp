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

pii idk[2001];
int dp[2001][2001][2], psa[2001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> idk[i].first >> idk[i].second;
	sort(idk + 1, idk + N + 1);

	for (int i = 1; i <= N; i++) psa[i] = psa[i - 1] + idk[i].second;

	for (int i = 1; i <= N; i++)
		if (idk[i].first == 0) dp[i][i][0] = dp[i][i][1] = idk[i].second;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j + i <= N; j++) {
			int l = j, r = j + i;
			int cl = max(dp[l + 1][r][0] - (idk[l + 1].first - idk[l].first), dp[l + 1][r][1] - (idk[r].first - idk[l].first)),
			    cr = max(dp[l][r - 1][1] - (idk[r].first - idk[r - 1].first), dp[l][r - 1][0] - (idk[r].first - idk[l].first));

			if (cl >= 0) dp[l][r][0] = max(dp[l][r][0], cl + idk[l].second);
			if (cr >= 0) dp[l][r][1] = max(dp[l][r][1], cr + idk[r].second);
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++)
			if (dp[i][j][0] > 0 || dp[i][j][1])
				ans = max(ans, psa[j] - psa[i - 1]);
	cout << ans << '\n';
	return 0;
}
