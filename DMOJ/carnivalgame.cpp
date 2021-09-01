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

bool g[2001][2001];
int t[2001], dp[2001][2001];
struct node {
	int r, c; bool b;
} p[2001][2001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; char c;
	cin >> N;
	for (int i = 1; i < N; i++)
		for (int j = 1; j <= i; j++)
			cin >> c, g[i][j] = c == 'R';
	for (int i = 1; i <= N; i++) cin >> t[i];
	memset(dp, INF, sizeof(dp)); dp[1][1] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= i; j++) {
			if (g[i][j]) {
				if (dp[i][j] < dp[i + 1][j + 1])
					dp[i + 1][j + 1] = dp[i][j], p[i + 1][j + 1] = {i, j, false};
				if (dp[i][j] + 1 < dp[i + 1][j])
					dp[i + 1][j] = dp[i][j] + 1, p[i + 1][j] = {i, j, true};
			} else {
				if (dp[i][j] < dp[i + 1][j])
					dp[i + 1][j] = dp[i][j], p[i + 1][j] = {i, j, false};
				if (dp[i][j] + 1 < dp[i + 1][j + 1])
					dp[i + 1][j + 1] = dp[i][j] + 1, p[i + 1][j + 1] = {i, j, true};
			}
		}
	}
	int mx = -INF, mi = -1;
	for (int i = 1; i <= N; i++)
		if (dp[N][i] != INF && t[i] - dp[N][i] > mx)
			mx = t[i] - dp[N][i], mi = i;
	vector<node> ans;
	for (node cur = {N, mi, false}; ; cur = p[cur.r][cur.c]) {
		if (cur.b) ans.push_back(cur);
		if (cur.r == 1 && cur.c == 1) break;
	}
	cout << mx << '\n' << ans.size() << '\n';
	for (auto i : ans) cout << i.r << ' ' << i.c << '\n';
	return 0;
}