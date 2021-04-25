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

int p[100001], ans[100001], to[100001];
bool vis[100001];

int main() {
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
	
	int N, M, K, L, R;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) p[i] = i;
	while (M--) {
		cin >> L >> R;
		for (int i = 0; L + i < R - i; i++) swap(p[L + i], p[R - i]);
	}

	for (int i = 1; i <= N; i++) to[p[i]] = i;
	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;
		vector<int> v = {i}; vis[i] = true;
		for (int cur = to[i]; cur != i; cur = to[cur]) v.push_back(cur), vis[cur] = true;
		for (int j = 0, sz = v.size(); j < sz; j++) ans[v[j]] = v[(j - K % sz + sz) % sz];
	}

	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
	return 0;
}
