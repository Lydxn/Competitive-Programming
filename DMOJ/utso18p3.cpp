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

bool vis[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, T, K, V, a, ans = 0, cur = 0;
	cin >> N >> T >> K >> V;
	while (V--) cin >> a, vis[a] = true;
	for (int i = 1; i < T; i++) cur += vis[i];
	for (int i = T; i <= N; i++) {
		cur += vis[i], cur -= vis[i - T];
		for (int j = i; j > i - T && cur < K; j--)
			if (!vis[j]) vis[j] = true, ++cur, ++ans;
	}
	cout << ans << '\n';
	return 0;
}
