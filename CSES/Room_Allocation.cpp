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

struct qu {
	int x, i; bool type;
	bool operator< (const qu &q) { return x < q.x || (x == q.x && type < q.type); }
} q[400000];
int ans[400000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		q[i << 1] = {a, i, 1}, q[i << 1 | 1] = {b + 1, i, 0};
	}

	sort(q, q + (n << 1)); set<int> r;
	for (int i = 1; i <= n; i++) r.insert(i);
	for (int i = 0; i < n << 1; i++) {
		if (q[i].type) ans[q[i].i] = *r.begin(), r.erase(r.begin());
		else r.insert(ans[q[i].i]);
	}

	int mx = 0;
	for (int i = 0; i < n; i++) mx = max(mx, ans[i]);
	cout << mx << '\n';
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
