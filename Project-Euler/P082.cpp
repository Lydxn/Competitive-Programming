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

int g[80][80], dp[80][80];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("p082_matrix.txt", "r", stdin);

	for (int i = 0; i < 80; i++) {
		string s, cur; int j = 0;
		cin >> s; s += ',';
		for (char c : s) {
			if (c == ',') g[i][j++] = stoi(cur), cur = "";
			else cur += c;
		}
	}

	for (int i = 0; i < 80; i++) dp[i][0] = g[i][0];
	for (int j = 1; j < 80; j++) {
		for (int i = 0; i < 80; i++)
			dp[i][j] = min(dp[i][j - 1], i ? dp[i - 1][j] : INF) + g[i][j];
		for (int i = 78; i >= 0; i--)
			dp[i][j] = min(dp[i][j], g[i][j] + dp[i + 1][j]);
	}

	int ans = INF;
	for (int i = 0; i < 80; i++) ans = min(ans, dp[i][79]);
	cout << ans << '\n';
	return 0;
}
