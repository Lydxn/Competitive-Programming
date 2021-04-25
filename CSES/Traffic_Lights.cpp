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

	int x, n, p;
	cin >> x >> n;
	multiset<int> ss; set<int> s;
	ss.insert(x), s.insert(0), s.insert(x);
	while (n--) {
		cin >> p;
		auto it = s.upper_bound(p);
		int r = *it, l = *--it;
		ss.insert(r - p), ss.insert(p - l), ss.erase(ss.find(r - l)), s.insert(p);
		cout << *ss.rbegin() << ' ';
	}
	cout << '\n';
	return 0;
}
