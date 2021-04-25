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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, N, S; ll ans = 0; char ch;
	cin >> M >> N >> S;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch;
			if (ch == 'X') {
				int minm = max(0, i - S + 1), maxm = min(i + S - 1, M - 1);
				int minn = max(0, j - S + 1), maxn = min(j + S - 1, N - 1);
				ans += (maxm - minm + 2 - S) * (maxn - minn + 2 - S);
			}
		}
	}
	cout << fixed << setprecision(10) << (double) ans / (M - S + 1) / (N - S + 1) << '\n';
	return 0;
}
