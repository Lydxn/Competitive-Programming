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

string S;
int dp[255][255];

int _solve(int l, int r) {
	if (l == r) return 1;
	if (l > r) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	if (S[l] == S[r]) return 2 + _solve(l + 1, r - 1);
	return dp[l][r] = max(_solve(l + 1, r), _solve(l, r - 1));
}

void solve() {
	cin >> S;
	memset(dp, -1, sizeof(dp));
	cout << _solve(0, int(S.size()) - 1) << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 5; _++) solve();
	return 0;
}
