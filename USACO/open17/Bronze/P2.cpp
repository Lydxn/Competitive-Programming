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

char g[2][100][100];
bool vis1[4], vis2[4];
unordered_map<char, int> mp = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
				cin >> g[i][j][k];
	int ans = 0;
	for (int i = 0; i < M; i++) {
		memset(vis1, false, 4); memset(vis2, false, 4);
		for (int j = 0; j < N; j++) vis1[mp[g[0][j][i]]] = true;
		for (int j = 0; j < N; j++) vis2[mp[g[1][j][i]]] = true;

		bool flag = true;
		for (int j = 0; j < 4; j++) flag &= vis1[j] + vis2[j] != 2;
		ans += flag;
	}
	cout << ans << '\n';
	return 0;
}
