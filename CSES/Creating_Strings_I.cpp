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

set<string> ss;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	sort(s.begin(), s.end());
	do {
		ss.insert(s);
	} while (next_permutation(s.begin(), s.end()));

	cout << ss.size() << '\n';
	for (auto i : ss) cout << i << '\n';
	return 0;
}
