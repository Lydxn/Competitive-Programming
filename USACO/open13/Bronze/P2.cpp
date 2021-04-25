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

int N, found[65536];

int f(int x) {
	int res = x;
	for (int i = 0; i < N; i++)
		if (x & (1 << i)) res ^= 1 << ((i + 1) % N);
	return res; 
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("blink.in", "r", stdin);
	freopen("blink.out", "w", stdout);

	int b, msk = 0; ll B;
	cin >> N >> B;
	for (int i = 0; i < N; i++) cin >> b, msk |= b << i;

	int c = -1, cur = msk;
	for (int i = 1; ; i++) {
		if (B == 0) break;
		if (found[cur]) { c = i - found[cur]; break; }
		found[cur] = i, cur = f(cur), --B;
	}

	if (B > 0) {
		B %= c;
		while (B--) cur = f(cur);
	}
	
	for (int i = 0; i < N; i++) cout << (cur >> i & 1) << '\n';
	return 0;
}
