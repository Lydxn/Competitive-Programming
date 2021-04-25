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

int nxt[101];
bool vis[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, I1, I2;
	while (cin >> N) {
		if (N == 0) break;

		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= N; i++) cin >> I1 >> I2, nxt[I1] = I2;

		int lcm = 1;
		for (int i = 1; i <= N; i++) {
			if (!vis[i]) {
				vis[i] = true;
				int cur = i, cnt = 1;
				while ((cur = nxt[cur]) != i) vis[cur] = true, ++cnt;
				lcm = lcm * cnt / __gcd(lcm, cnt);
			}
		}
		cout << lcm << '\n';
	}
	return 0;
}
