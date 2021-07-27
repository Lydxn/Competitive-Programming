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

char g[2000][2000];
bool vis[2000][2000];
set<pii> cur, nxt;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> g[i][j];
	string ans; cur.emplace(0, 0);
	while (!cur.empty()) {
		char mn = 'z';
		for (auto i : cur) mn = min(mn, g[i.first][i.second]);
		ans += mn;
		for (auto i : cur) {
			if (g[i.first][i.second] != mn) continue;
			if (i.first != N - 1) nxt.emplace(i.first + 1, i.second);
			if (i.second != M - 1) nxt.emplace(i.first, i.second + 1);
		}
		cur = nxt; nxt.clear();
	}
	cout << ans << '\n';
	return 0;
}
