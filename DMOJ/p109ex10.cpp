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

	int x;
	cin >> x;

	int q = x / 25, d = (x - q * 25) / 10, n = (x - q * 25 - d * 10) / 5, c = (x - q * 25 - d * 10 - n * 5);
	cout << x << " cent" << (x == 1 ? "" : "s") << " requires ";

	bool first = false;
	if (q) cout << (first ? ", " : "") << q << " quarter" << (q == 1 ? "" : "s"), first = true;
	if (d) cout << (first ? ", " : "") << d << " dime" << (d == 1 ? "" : "s"), first = true;
	if (n) cout << (first ? ", " : "") << n << " nickel" << (n == 1 ? "" : "s"), first = true;
	if (c) cout << (first ? ", " : "") << c << " cent" << (c == 1 ? "" : "s"), first = true;
	cout << ".\n";
	return 0;
}