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

int a[100], s[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);

	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	memcpy(s, a, sizeof(a)), sort(s, s + N);
	for (int i = 0; i < N; i++) ans += s[i] != a[i];
	cout << max(0, ans - 1) << '\n';
	return 0;
}
