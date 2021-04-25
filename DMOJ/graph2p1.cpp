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

int N, adj[1000][1000];
vector<int> ans[1000];
bool vis[1000];

void dfs(int cur, int rep) {
	vis[cur] = true, ans[rep].push_back(cur);
	for (int i = 0; i < N; i++)
		if (!vis[i] && adj[cur][i]) dfs(i, rep);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> adj[i][j];

	for (int i = 0; i < N; i++)
		if (!vis[i]) dfs(i, i);

	for (int i = 0; i < N; i++) {
		if (ans[i].empty()) continue;
		int sz = ans[i].size();
		sort(ans[i].begin(), ans[i].begin() + sz);
		for (int j = 0; j < sz; j++) cout << ans[i][j] + 1 << ' ';
		cout << '\n';
	}
	return 0;
}
