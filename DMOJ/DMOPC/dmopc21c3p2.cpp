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

int ans[1000000], aidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll K;
	cin >> K;
	if (K == 0) { cout << "1\n1\n"; return 0; }
	ll a = 0, b = 1e6; bool good = false;
	for (; a <= 1e6; a++) {
		while (b > 0 && a * (a - 1) / 2 + b * (b + 1) / 2 > K) --b;
		if (a * (a - 1) / 2 + b * (b + 1) / 2 == K && a + b <= 1e6)
			{ good = true; break; }
	}
	if (!good) { cout << "-1\n"; return 0; }
	cout << a + b << '\n';
	ans[b] = 1;
	for (int i = 0; i < a + b; i++) cout << ans[i] << " \n"[i == a + b - 1];
	return 0;
}
