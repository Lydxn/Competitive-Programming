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

int x[501], y[501], r[501];
bool vis[501];
queue<int> q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int B, Q, a, b;
	cin >> B >> Q;
	for (int i = 1; i <= B; i++) cin >> x[i] >> y[i] >> r[i];
	while (Q--) {
		cin >> a >> b;
		memset(vis, false, sizeof(vis)); q.push(a); vis[a] = true;
		while (!q.empty()) {
			int cv = q.front(); q.pop();
			for (int i = 1; i <= B; i++)
				if (!vis[i] && i != cv && (x[cv] - x[i]) * (x[cv] - x[i]) + (y[cv] - y[i]) * (y[cv] - y[i]) <= r[cv] * r[cv])
					q.push(i), vis[i] = true;
		}
		cout << (vis[b] ? "YES" : "NO") << '\n';
	}
	return 0;
}
