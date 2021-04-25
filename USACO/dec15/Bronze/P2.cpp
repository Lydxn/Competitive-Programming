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

int cntn[100], cntm[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

	int N, M, l, s;
	cin >> N >> M;
	
	for (int cur = 0; N--; ) {
		cin >> l >> s;
		for (int i = cur; i < cur + l; i++) cntn[i] = s;
		cur += l;
	}

	for (int cur = 0; M--; ) {
		cin >> l >> s;
		for (int i = cur; i < cur + l; i++) cntm[i] = s;
		cur += l;
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) ans = max(ans, cntm[i] - cntn[i]);
	cout << ans << '\n';
	return 0;
}
