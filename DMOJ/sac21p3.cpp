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

	int N, P, M, CS, E; ll mx = -INFL, mn = INFL; string s, mxa, mna;
	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		cin >> s >> M >> CS >> E;
		// Note: (int) rounds up on negative numbers
		ll x = floor(sqrt(16 * M) + 3 * pow(CS, P) - 4 * E);
		if (x > mx) mx = x, mxa = s;
		if (x < mn) mn = x, mna = s;
	}
	cout << mxa << ' ' << mx << '\n';
	cout << mna << ' ' << mn << '\n';
	return 0;
}
