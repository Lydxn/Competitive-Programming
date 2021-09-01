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

bool g[10][10];
int cnt[1 << 20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, G, ans = 0; char c;
	cin >> N >> G;
	while (G--) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> c, g[i][j] = c == 'R';
		for (int i = 0; i < N - 1; i++)
			for (int j = 0; j < N - 1; j++)
				if (g[i][j])
					g[i][j] ^= 1, g[i + 1][j] ^= 1, g[i][j + 1] ^= 1, g[i + 1][j + 1] ^= 1;
		int msk = 0;
		for (int i = 0; i < N; i++) msk = msk << 2 | g[N - 1][i] << 1 | g[i][N - 1];
		ans += cnt[msk]++;
	}
	cout << ans << '\n';
	return 0;
}
