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

set<int> p, cur;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size(); s += s;
	char mn = 'z';
	for (int i = 0; i < n; i++) mn = min(mn, s[i]);
	for (int i = 0; i < n; i++)
		if (s[i] == mn) p.insert(i);
	for (int i = 1; i < n; i++) {
		mn = 'z';
		for (int j : p) mn = min(mn, s[j + 1]);
		for (int j : p) {
			if (s[j + 1] != mn) continue;
			auto it = p.lower_bound(j);
			if (it == p.begin() || *prev(it) < j - i)
				cur.insert(j + 1);
		}
		p = cur, cur.clear();
	}
	cout << s.substr(*p.begin() - n + 1, n) << '\n';
	return 0;
}
