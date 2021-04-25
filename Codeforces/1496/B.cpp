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

bool vis[100001];
int a[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k; memset(vis, false, sizeof(vis));
		int mx = 0, mex = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i], mx = max(mx, a[i]);
			if (a[i] <= n) vis[a[i]] = true;
		}
		while (vis[mex]) ++mex;

		if (k == 0) cout << n << '\n';
		else if (mex == mx + 1) cout << n + k << '\n';
		else {
			bool in = false;
			for (int i = 0; i < n; i++) in |= a[i] == (mex + mx + 1) / 2;
			cout << n + !in << '\n';
		}
	}
	return 0;
}
