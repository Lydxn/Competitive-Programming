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

int A[101], B[101], C[101], idx[101];
bool vis[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("reorder.in", "r", stdin);
	freopen("reorder.out", "w", stdout);

	int N, cnt = 0, mx = -1;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i], idx[B[i]] = i;
	for (int i = 1; i <= N; i++) {
		if (vis[i] || A[i] == B[i]) continue;
		int cur = 0;
		while (!vis[i]) vis[i] = true, i = idx[A[i]], ++cur;
		++cnt, mx = max(mx, cur);
	}
	cout << cnt << ' ' << mx << '\n';
	return 0;
}
