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

	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);

	int A, B, N, C, M, c, ans = INF;
	cin >> A >> B >> N;
	for (int i = 0; i < N; i++) {
		cin >> C >> M;
		int aidx = INF, bidx = INF;
		for (int j = 0; j < M; j++) {
			cin >> c;
			if (c == A) aidx = min(aidx, j);
			if (c == B) bidx = min(bidx, j);
		}

		if (aidx != INF && bidx != INF && aidx < bidx)
			ans = min(ans, C);
	}
	cout << (ans == INF ? -1 : ans) << '\n';
	return 0;
}
