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

int d[10];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K, D, mn = INF; bool z = false;
	cin >> K >> D;
	for (int i = 0; i < D; i++) {
		cin >> d[i];
		if (d[i] > 0) mn = min(mn, d[i]);
		z |= d[i] == 0;
	}
	if (mn != INF && !z) {
		for (int i = 0; i < K; i++) cout << mn;
		cout << '\n';
	} else if (mn != INF && z) {
		if (K > 1) cout << mn;
		for (int i = 0; i < K - 2; i++) cout << 0;
		cout << mn << '\n';
	}
	else if (mn == INF) cout << "-1\n";
	else assert(false);
	return 0;
}