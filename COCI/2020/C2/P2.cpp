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

ll x[1000], y[1000]; int n;
bool vis[1000];
queue<int> q;

bool f(ll r) {
	memset(vis, false, sizeof(vis));
	q.push(0), vis[0] = true; int num = 1;
	while (!q.empty()) {
		int cv = q.front(); q.pop();
		for (int i = 0; i < n; i++) {
			if (i == cv || vis[i]) continue;
			if ((x[i] - x[cv]) * (x[i] - x[cv]) + (y[i] - y[cv]) * (y[i] - y[cv]) <= r)
				q.push(i), vis[i] = true, ++num;
		}
	}
	return num == n;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	ll l = 0, r = 2e18, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (f(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << fixed << setprecision(10) << sqrt(r + 1) / 2 << '\n';
 	return 0;
}
