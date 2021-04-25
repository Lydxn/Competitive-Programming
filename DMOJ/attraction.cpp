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

int P[200000], D[600000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, A, B;
	cin >> T;
	while (T--) {
		cin >> N >> A >> B;
		for (int i = 0; i < A; i++) cin >> P[i];
		sort(P, P + A);

		int didx = 0;
		if (P[0] - 1 > 0) D[didx++] = P[0] - 1;
		if (N - P[A - 1] > 0) D[didx++] = N - P[A - 1];
		
		int d1 = 0;
		for (int i = 1; i < A; i++) {
			int d = P[i] - P[i - 1] - 1;
			if (d == 0) continue;
			else if (d == 1) D[didx++] = 1;
			else if (d == 3) D[didx++] = 2, ++d1;
			else if (d % 2) D[didx++] = (d + 1) / 2, D[didx++] = d / 2 - 1, D[didx++] = 1;
			else D[didx++] = d / 2, D[didx++] = d / 2;
		}

		sort(D, D + didx, greater<int>());
		int ans = 0;
		for (int i = 0; i < min(B, didx); i++) ans += D[i];
		if (B > didx) ans += min(B - didx, d1 * 2) / 2;
		cout << ans << '\n';
	}
	return 0;
}
