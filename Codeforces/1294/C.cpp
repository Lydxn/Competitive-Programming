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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int a = -1, b = -1;
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0) { a = i, n /= i; break; }
		if (a == -1) { cout << "NO\n"; continue; }
		for (int i = 2; i * i <= n; i++)
			if (i != a && n % i == 0) { b = i, n /= i; break; }
		if (b == -1) { cout << "NO\n"; continue; }
		if (a == n || b == n) { cout << "NO\n"; continue; }
		else cout << "YES\n" << a << ' ' << b << ' ' << n << '\n';
	}
	return 0;
}
