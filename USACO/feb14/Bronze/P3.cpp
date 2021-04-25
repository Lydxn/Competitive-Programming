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

int ans;

void solve(string S) {
	++ans;
	int sz = S.size();
	if (sz % 2 == 0 || sz < 3) return;
	if (S.substr(0, sz / 2) == S.substr(sz / 2 + 1))
		solve(S.substr(0, sz / 2 + 1));
	if (S.substr(1, sz / 2) == S.substr(sz / 2 + 1))
		solve(S.substr(0, sz / 2 + 1));
	if (S.substr(0, sz / 2) == S.substr(sz / 2, sz / 2))
		solve(S.substr(sz / 2));
	if (S.substr(0, sz / 2) == S.substr(sz / 2 + 1, sz / 2))
		solve(S.substr(sz / 2));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("scode.in", "r", stdin);
	freopen("scode.out", "w", stdout);

	string S;
	cin >> S;
	solve(S);
	cout << ans - 1 << '\n';
	return 0;
}
