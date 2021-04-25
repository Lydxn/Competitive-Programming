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

const int MAXN = 101;
int dp[MAXN][MAXN];

int solve(int k, int prev) {
	if (k == 0) return 1;
	if (dp[k][prev] != -1) return dp[k][prev];

	int res = 0;
	for (int i = 1; i <= min(k, prev); i++)
		res += solve(k - i, i);
	return dp[k][prev] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, k, a; vector<int> ans;
	cin >> N;
	while (N--) {
		cin >> k >> a;
		memset(dp, -1, sizeof(dp)); ans.clear();

		while (k > 0) {
			int cur = -1;
			for (int i = 1; i <= k; i++) {
				int sz = solve(k - i, i);
				if (sz >= a) {
					cur = i;
					break;
				}
				a -= sz;
			}

			if (cur == -1) {
				cout << "Too big\n";
				goto done;
			}

			ans.push_back(cur);
			k -= cur;
		}

		cout << '(';
		for (int i = 0, sz = ans.size(); i < sz; i++) {
			cout << ans[i];
			if (i != sz - 1) cout << ',';
		}
		cout << ")\n";
		done:;
	}
	return 0;
}
