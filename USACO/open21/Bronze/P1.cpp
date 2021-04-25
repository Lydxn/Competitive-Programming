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

int c[100000], f[100002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> c[i], ++f[c[i]];
	int h = 100000;
	for (; ; h--) {
		f[h] += f[h + 1];
		if (f[h] >= h) break;
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) cnt += c[i] == h;
	cout << h + (f[h + 1] + min(cnt, L) >= (h + 1)) << '\n';
	return 0;
}
