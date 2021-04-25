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

ll grid[41][41];
unordered_map<ll, int> cnt;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int C, R, M, Q, x, y, f; ll B, O; char op;
	cin >> C >> R >> M >> Q;
	
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			grid[i][j] = 1;
			
	while (M--) {
		cin >> op >> x >> y >> f;
		if (op == 'r')
			for (int i = x; i <= y; i++)
				for (int j = 1; j <= C; j++)
					grid[i][j] *= f;
		else
			for (int i = 1; i <= R; i++)
				for (int j = x; j <= y; j++)
					grid[i][j] *= f;
	}
	
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
	
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			for (int k = i; k <= R; k++)
				for (int l = j; l <= C; l++)
					++cnt[grid[k][l] - grid[i - 1][l] - grid[k][j - 1] + grid[i - 1][j - 1]];
	
	while (Q--) {
		cin >> B >> O;
		if (B == 0 && O == 0) cout << (ll) C * (C + 1) * R * (R + 1) / 4 << '\n';
		else if (B == 0 || O % B) cout << "0\n";
		else cout << cnt[O / B] << '\n';
	}
	return 0;
}
