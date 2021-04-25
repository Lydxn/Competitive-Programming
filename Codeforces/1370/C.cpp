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

bool f(int n) {
	if (n == 1) return false;
	if (n == 2 || n % 2) return true;
	int cnt2 = 0; bool p = true;
	while (n % 2 == 0) n /= 2, ++cnt2;
	for (int i = 2; i * i <= n; i++)
		p &= n % i != 0;
	return !((cnt2 == 1 && p) || n == 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (f(n) ? "Ashishgup" : "FastestFinger") << '\n';
	}
	return 0;
}
