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

bool adj[500][500], vis[500][500];
int N;

void flood(int cur, int s) {
	if (vis[s][cur]) return;
	vis[s][cur] = true;
	for (int i = 0; i < N; i++)
		if (adj[cur][i]) flood(i, s);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N; char ch;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ch, adj[i][j] = ch - '0';

	for (int i = 0; i < N; i++)
		flood(i, i);

	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			ans += !vis[i][j] && !vis[j][i];
	cout << ans << '\n';
	return 0;
}
