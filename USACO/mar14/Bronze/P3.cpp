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

char G[100][100];
bool vis[100][100];
int N;

void dfs(char c, int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= N || G[i][j] != c || vis[i][j]) return;
	vis[i][j] = true;
	dfs(c, i + 1, j), dfs(c, i - 1, j), dfs(c, i, j - 1), dfs(c, i, j + 1);
}

int flood() {
	int cnt = 0; memset(vis, false, sizeof(vis));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!vis[i][j]) ++cnt, dfs(G[i][j], i, j);
	return cnt;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("cowart.in", "r", stdin);
	freopen("cowart.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> G[i][j];

	cout << flood() << ' ';
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (G[i][j] == 'G') G[i][j] = 'R';
	cout << flood() << '\n';
	return 0;
}
