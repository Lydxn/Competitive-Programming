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

bool G[2000][2000];
ll dp[2000][2000];
deque<int> dq, pdq;

double cross(int i, int j, int k) {
	int b1 = dp[i][j] + 1LL * j * j, b2 = dp[i][k] + 1LL * k * k;
	return (b2 - b1) / (2.0 * (k - j));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, C; char ch;
	cin >> N >> C;
	for (int i = 0; i < C; i++)
		for (int j = 0; j < N; j++)
			cin >> ch, G[i][j] = ch == '1';
	memset(dp, INFL, sizeof(dp));
	for (int i = 0; i < C; i++)
		if (G[i][0]) dp[0][i] = 0, pdq.push_back(i);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < C; j++) {
			if (!G[j][i]) continue;
			while (pdq.size() >= 2 && cross(i - 1, pdq[0], pdq[1]) < j)
				pdq.pop_front();
			dp[i][j] = dp[i - 1][pdq[0]] + 1LL * (j - pdq[0]) * (j - pdq[0]);
			while (dq.size() >= 2 && cross(i, dq[dq.size() - 2], j) < cross(i, dq[dq.size() - 2], dq.back()))
				dq.pop_back();
			dq.push_back(j);
		}
		pdq = dq, dq.clear();
	}
						
	ll ans = INFL;
	for (int i = 0; i < C; i++)
		if (G[i][N - 1]) ans = min(ans, dp[N - 1][i]);
	cout << ans << '\n';
	return 0;
}