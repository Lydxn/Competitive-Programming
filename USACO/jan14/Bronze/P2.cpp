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

int T[10000], D[10000], tidx, didx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("slowdown.in", "r", stdin);
	freopen("slowdown.out", "w", stdout);

	int N, x; char c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c >> x;
		if (c == 'T') T[tidx++] = x;
		else D[didx++] = x;
	}

	sort(T, T + tidx, greater<int>()), sort(D, D + didx, greater<int>());
	double t = 0, d = 0; int s = 0; --tidx, --didx;
	while (true) {
		++s;
		if (didx >= 0 && (tidx < 0 || T[tidx] >= t + (D[didx] - d) * s))
			t += (D[didx] - d) * s, d = D[didx--];
		else if (tidx >= 0)
			d += (T[tidx] - t) / s, t = T[tidx--];
		else {
			cout << (int) round(t + (1000 - d) * s) << '\n';
			break;
		}
	}
	return 0;
}
