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

	int T; string s;
	cin >> T;
	while (T--) {
		cin >> s;
		int X = 0, O = 0;
		for (int i = 0; i < 9; i++)
			if (s[i] != '.') ++(s[i] == 'X' ? X : O);

		if (!(X == O || X - O == 1)) cout << "no\n";
		else {
			int wx = 0, wo = 0;
			for (int i = 0; i < 9; i += 3)
				if (s[i] != '.' && s[i] == s[i + 1] && s[i + 1] == s[i + 2])
					++(s[i] == 'X' ? wx : wo);
			for (int i = 0; i < 3; i++)
				if (s[i] != '.' && s[i] == s[i + 3] && s[i + 3] == s[i + 6])
					++(s[i] == 'X' ? wx : wo);
			if (s[0] != '.' && s[0] == s[4] && s[4] == s[8])
				++(s[0] == 'X' ? wx : wo);
			if (s[2] != '.' && s[2] == s[4] && s[4] == s[6])
				++(s[2] == 'X' ? wx : wo);
			cout << ((wx > 0 && wo > 0) || (X == O && wx > 0) || (X != O && wo > 0) ? "no" : "yes") << '\n';
		}
	}
	return 0;
}
