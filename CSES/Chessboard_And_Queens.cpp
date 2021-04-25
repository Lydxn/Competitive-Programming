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

int ans;
char grid[8][8];
bool col[8], d1[15], d2[15];

void solve(int r) {
	if (r == 8) ++ans;
	else {
		for (int c = 0; c < 8; c++) {
			if (grid[r][c] == '.') {
				bool &b0 = col[c], &b1 = d1[r + c], &b2 = d2[c - r + 7];
				if (!b0 && !b1 && !b2)
					b0 = b1 = b2 = true, solve(r + 1), b0 = b1 = b2 = false;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> grid[i][j];

	solve(0);
	cout << ans << '\n';
	return 0;
}
