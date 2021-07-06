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

int l[200000], g[200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int L, G;
	cin >> L >> G;
	for (int i = 0; i < L; i++) cin >> l[i];
	for (int i = 0; i < G; i++) cin >> g[i];
	sort(l, l + L, greater<int>()), sort(g, g + G, greater<int>());
	for (int i = 0, j = 0; i < G; i++) {
		while (l[j] >= g[i]) ++j;
		if (i > j - 1) { cout << g[i] << '\n'; return 0; }
	}
	cout << "-1\n";
	return 0;
}
