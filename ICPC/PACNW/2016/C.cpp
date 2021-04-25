#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

bool b[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k, r;
	cin >> n >> k >> r;
	for (int i = 0, x; i < k; i++) cin >> x, b[x] = true;

	int ans = 0, cnt = 0;
	for (int i = 1; i < r; i++) cnt += b[i];
	for (int i = r; i <= n; i++) {
		cnt += b[i] - b[i - r];
		if (cnt == 1) {
			if (!b[i]) b[i] = true;
			else b[i - 1] = true;
			++ans, ++cnt;
		} else if (cnt == 0) {
			b[i] = b[i - 1] = true;
			ans += 2, cnt += 2;
		}
	}
	cout << ans << '\n';
	return 0;
}
