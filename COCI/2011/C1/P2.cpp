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

int d1[501][501], d2[501][501];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> x;
			for (int k = 0; i + k <= N && j + k <= N; k++)
				d1[i + k][j + k] += x;
			for (int k = 0; i + k <= N && j - k > 0; k++)
				d2[i + k][j - k] += x;
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (i - k >= 0 && j - k >= 0) {
					int A = d1[i][j] - d1[i - k][j - k], B = d2[i][j - k + 1] - d2[i - k][j + 1];
					ans = max(ans, A - B);
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
