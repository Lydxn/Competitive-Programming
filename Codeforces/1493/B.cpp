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

int mp[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

int rev(int x) {
	if (mp[x % 10] == -1 || mp[x / 10] == -1) return INF;
	return mp[x % 10] * 10 + mp[x / 10];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, h, m; string s;
	cin >> T;
	while (T--) {
		cin >> h >> m >> s;
		int ch = stoi(s.substr(0, 2)), cm = stoi(s.substr(3));
		while (true) {
			if (rev(ch) < m && rev(cm) < h) {
				cout << setfill('0') << setw(2) << ch << ':' << setw(2) << cm << '\n';
				break;
			}

			++cm;
			if (cm == m) cm = 0, ++ch;
			if (ch == h) ch = cm = 0;
		}
	}
	return 0;
}
