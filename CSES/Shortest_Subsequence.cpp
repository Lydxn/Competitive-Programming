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

	string s; int msk = 0;
	cin >> s;
	for (char c : s) {
		int v = (c >> 1) & 3;
		if (!(msk & (1 << v))) {
			msk |= 1 << v;
			if (msk == 15)
				cout << c, msk = 0;
		}
	}
	for (int i = 0; i < 4; i++)
		if (!(msk & (1 << i)))
			{ cout << "ACTG"[i]; break; }
	return 0;
}
