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

int f[1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0, a; i < N; i++) cin >> a, ++f[a];

	int mx = 0, cnt = 0;
	for (int i = 10; i <= 1000; i++)
		if (mx < f[i]) mx = f[i], cnt = 1;
		else if (mx == f[i]) ++cnt;
	cout << cnt << '\n';
	for (int i = 10; i <= 1000; i++)
		if (mx == f[i]) cout << i << '\n';
	return 0;
}
