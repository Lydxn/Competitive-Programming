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

int grid[50][50];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> grid[i][j];

		bool magic = true;
		int sum0 = accumulate(grid[0], grid[0] + N, 0);
		for (int i = 0; i < N; i++) {
			int sum1 = 0, sum2 = 0;
			for (int j = 0; j < N; j++) sum1 += grid[i][j], sum2 += grid[j][i];
			magic &= sum0 == sum1 && sum0 == sum2;
		}
		cout << (magic ? "yes" : "no") << '\n';
	}
	return 0;
}
