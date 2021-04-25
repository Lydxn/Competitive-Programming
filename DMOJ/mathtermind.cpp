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

int M[7], G[7];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, N, g;
	cin >> R;
	for (int i = 0; i < R; i++) {
		cin >> N >> M[i];
		while (N--) cin >> g, G[i] |= 1 << g;
	}
	
	int a = -1, b = -1, c = -1, cnt = 0;
	for (int i = 1; i <= 15; i++) {
		for (int j = i + 1; j <= 15; j++) {
			for (int k = j + 1; k <= 15; k++) {
				int msk = (1 << i) | (1 << j) | (1 << k);
				bool yay = true;
				for (int l = 0; l < R; l++)
					yay &= __builtin_popcount(G[l] & msk) == M[l];
				if (yay) a = i, b = j, c = k, ++cnt;
			}
		}
	}
	
	if (cnt > 1) cout << cnt << '\n';
	else if (cnt == 1) cout << a << ' ' << b << ' ' << c << '\n';
	else cout << "-1\n";
	return 0;
}
