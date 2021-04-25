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

int a[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x, a[i] = -x;
	for (int i = 0; i < N; i++) cin >> x, a[i] += x;
	for (int i = 0; i < N; i++) {
		while (a[i]) {
			int go = i, cur = 0, mx = 0;
			for (int j = i; j < N; j++) {
				cur += a[i] * a[j] > 0 ? 1 : -1;
				if (cur > mx) mx = cur, go = j;
			}
			
			int sgn = a[i] > 0 ? 1 : -1;
			for (int j = i; j <= go; j++) a[j] -= sgn;
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}
