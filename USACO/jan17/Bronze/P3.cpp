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

bool grid[10][10];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);

	int N; char ch;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ch, grid[i][j] = ch == '1';

	int ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			if (grid[i][j]) {
				++ans;
				for (int a = 0; a <= i; a++)
					for (int b = 0; b <= j; b++)
						grid[a][b] ^= 1;
			}
		}
	}
	cout << ans << '\n';
	
	return 0;
}
