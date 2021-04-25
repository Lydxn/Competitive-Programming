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

ll v[100001], u[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, t, l, r;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i];
	memcpy(u, v, sizeof(u)), sort(u + 1, u + n + 1);
	for (int i = 1; i <= n; i++) v[i] += v[i - 1], u[i] += u[i - 1];
	
	cin >> m;
	while (m--) {
		cin >> t >> l >> r;
		if (t == 1) cout << v[r] - v[l - 1] << '\n';
		else cout << u[r] - u[l - 1] << '\n';
	}
	return 0;
}
