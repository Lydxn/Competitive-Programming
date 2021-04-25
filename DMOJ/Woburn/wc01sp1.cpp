// WIP

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

char grid[60][60];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; char ch;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];
	cin >> ch;
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					if (i + r >= N || j + c >= N) continue;
					if (i + c >= N || j - r < 0) continue;
					if (i + r + c >= N || j + c - r < 0) continue;
					if ((grid[i][j] == ch) + (grid[i + r][j + c] == ch) + (grid[i + c][j - r] == ch) + (grid[i + r + c][j + c - r] == ch) < 3) continue;
					if (grid[i][j] != '*' && grid[i + r][j + c] != '*' && grid[i + c][j - r] != '*' && grid[i + r + c][j + c - r] != '*') continue;
					ans = max(ans, r * r + c * c);
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
