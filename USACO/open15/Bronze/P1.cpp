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

int N, M;
char grid[50][50];
pii dir[] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

int f(char x, char y) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (pii d : dir) {
				int r1 = i + d.first, c1 = j + d.second, r2 = r1 + d.first, c2 = c1 + d.second;
				if (r2 >= 0 && r2 < N && c2 >= 0 && c2 < M)
					res += grid[i][j] == x && grid[r1][c1] == y && grid[r2][c2] == y;
			}
		}
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("moocrypt.in", "r", stdin);
	freopen("moocrypt.out", "w", stdout);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> grid[i][j];

	int ans = 0;
	for (char c = 'A'; c <= 'Z'; c++)
		for (char d = 'A'; d <= 'Z'; d++)
			if (c != 'M' && d != 'O' && c != d) ans = max(ans, f(c, d));
	cout << ans << '\n';
	return 0;
}
