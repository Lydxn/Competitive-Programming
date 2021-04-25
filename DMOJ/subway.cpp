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

vector<int> adj[50001];
ll h[50001], nh[50001], d, nd;

void dfs(int cur, int prev) {
	nh[cur] = 1;
	for (int i : adj[cur]) {
		if (i == prev) continue;
		dfs(i, cur);

		if (d < h[cur] + h[i] + 1) d = h[cur] + h[i] + 1, nd = nh[cur] * nh[i];
		else if (d == h[cur] + h[i] + 1) nd += nh[cur] * nh[i];
		if (h[cur] < h[i] + 1) h[cur] = h[i] + 1, nh[cur] = nh[i];
		else if (h[cur] == h[i] + 1) nh[cur] += nh[i];
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x, y;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		adj[x].push_back(y), adj[y].push_back(x);
	}

	dfs(1, -1);
	cout << nd << '\n';
	return 0;
}
