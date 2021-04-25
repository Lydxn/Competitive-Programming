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

	string s; bool yes = false;
	for (int i = 0; i < 5; i++) {
		cin >> s;
		for (int j = 0; j < int(s.size()) - 2; j++)
			if (s[j] == 'F' && s[j + 1] == 'B' && s[j + 2] == 'I')
				{ cout << i + 1 << ' '; yes = true; break; }
	}
	if (!yes) cout << "HE GOT AWAY!\n";
	return 0;
}
