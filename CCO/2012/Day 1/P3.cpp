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

bool r0[26][26];
vector<int> r1[26];
int dp[30][30][26];
string S;

int solve(int l, int r, int st) {
	if (l == r) return r0[st][S[l] - 'a'];
	if (dp[l][r][st] != -1) return dp[l][r][st];
	for (int i = l; i < r; i++)
		for (int j : r1[st])
			if (solve(l, i, j >> 5) && solve(i + 1, r, j & 31))
				return dp[l][r][st] = 1;
	return dp[l][r][st] = 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int V, T, R1, R2, W, st; char _, c0, c1, c2;
	cin >> V >> T >> _; st = _ - 'A';
	for (int i = 1; i < V + T; i++) cin >> _;
	cin >> R1;
	while (R1--) cin >> c0 >> c1, r0[c0 - 'A'][c1 - 'a'] = true;
	cin >> R2;
	while (R2--) cin >> c0 >> c1 >> c2, r1[c0 - 'A'].push_back((c1 - 'A') << 5 | (c2 - 'A'));
	cin >> W;
	while (W--) {
		cin >> S;
		memset(dp, -1, sizeof(dp));
		cout << solve(0, int(S.size()) - 1, st) << '\n';
	}
	return 0;
}
