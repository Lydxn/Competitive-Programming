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

int a[1000001], psa[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, D, n;
	cin >> N >> D;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++) psa[i] = psa[i - 1] + a[i];

	int l = 1, r = N;
	while (D--) {
		cin >> n;
		int s1 = psa[l + n - 1] - psa[l - 1], s2 = psa[r] - psa[l + n - 1];
		if (s1 >= s2) cout << s1 << '\n', l = l + n;
		else cout << s2 << '\n', r = l + n - 1;
	}
	return 0;
}
