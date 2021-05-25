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

bool adj[20][20];
int msk[20], cnt[20], vis[1 << 20];
ll s[1 << 20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, H; char c;
	cin >> N >> H;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> c, adj[i][j] = c == '1', msk[i] |= adj[i][j] << j, cnt[i] += adj[i][j];
	ll ans = cnt[0]; int cur = msk[0]; s[vis[cur] = 1] = cnt[0];
	for (int i = 2; i <= H; i++) {
		int nxt = 0;
		for (int j = 0; j < N; j++) {
			if (cur & (1 << j)) nxt ^= msk[j], ans += cnt[j];
			else ans += cnt[j] << 1;
		}
		if (vis[nxt]) {
			int x = (H - i) / (i - vis[nxt]);
			ans += (ans - s[vis[nxt]]) * x + s[vis[nxt] + (H - i) % (i - vis[nxt])] - s[vis[nxt]];
			break;
		}
		vis[nxt] = i, s[i] = ans, cur = nxt;
	}
	cout << ans << '\n';
	return 0;
}
