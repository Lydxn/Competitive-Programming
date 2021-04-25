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

int a[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	if (a[0] != -1 && a[0] != 0) { cout << "-1\n"; return 0; }
	a[0] = 0;
	for (int i = N - 1, cur = -1; i >= 0; i--) {
		if (a[i] != -1 && cur != -1 && cur != a[i]) { cout << "-1\n"; return 0; }
		if (a[i] == -1) a[i] = cur;
		if (a[i] != -1) cur = a[i];
		if (cur >= 0) --cur;
	}

	int mn = 0, mx = 0;
	for (int i = 0; i < N; i++) mn += !a[i], mx += a[i] == -1;
	cout << mn << ' ' << mn + mx << '\n';
	return 0;
}
