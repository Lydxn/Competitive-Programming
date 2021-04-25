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

int N, a[100], b[100], g[100];

int f(int x) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (x == a[i]) x = b[i];
		else if (x == b[i]) x = a[i];
		cnt += x == g[i];
	}
	return cnt;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> g[i];
	cout << max(max(f(1), f(2)), f(3)) << '\n';
	return 0;
}
