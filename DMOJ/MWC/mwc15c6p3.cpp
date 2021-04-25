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

ll s[1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, S, x;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> S;
		while (S--) cin >> x, s[i] |= 1LL << (x + 30);
	}

	while (Q--) {
		cin >> S; ll ans = 0;
		while (S--) cin >> x, ans ^= s[x];
		cout << __builtin_popcountll(ans);
		for (int i = 0; i < 62; i++)
			if ((ans >> i) & 1) cout << ' ' << i - 30;
		cout << '\n';
	}
	return 0;
}
