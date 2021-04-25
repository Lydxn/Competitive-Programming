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

int N;
ll BIT[200001];

void update(int i, ll x) {
	for (; i <= N; i += i & -i) BIT[i] = max(BIT[i], x);
}

ll query(int i) {
	ll res = 0;
	for (; i; i -= i & -i) res = max(res, BIT[i]);
	return res;
}

int h[200000], a[200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> h[i];
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) update(h[i], query(h[i]) + a[i]);
	cout << query(N) << '\n';
	return 0;
}
