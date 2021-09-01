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

int g[50][50];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M; ll ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> g[i][j];
	for (int i = 0; i < N; i++)
		if (!g[i][0])
			for (int j = 0; j < M; j++)
				g[i][j] ^= true;
	for (int i = 0; i < M; i++) {
		int s = 0;
		for (int j = 0; j < N; j++) s += g[j][i];
		if (s <= N / 2)
			for (int j = 0; j < N; j++)
				g[j][i] ^= true;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans += (ll) g[i][j] << (M - j - 1);
	cout << ans << '\n';
	return 0;
}
