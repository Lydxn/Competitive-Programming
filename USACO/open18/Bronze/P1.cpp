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

	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);

	char grid[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> grid[i][j];

	set<char> cnt;
	set<set<char>> ans1, ans2;
	
	for (int i = 0; i < 3; i++) {
		cnt.clear();
		for (int j = 0; j < 3; j++) cnt.insert(grid[i][j]);
		if (cnt.size() == 1) ans1.insert(cnt);
		if (cnt.size() == 2) ans2.insert(cnt);

		cnt.clear();
		for (int j = 0; j < 3; j++) cnt.insert(grid[j][i]);
		if (cnt.size() == 1) ans1.insert(cnt);
		if (cnt.size() == 2) ans2.insert(cnt);
	}

	cnt.clear();
	for (int i = 0; i < 3; i++) cnt.insert(grid[i][i]);
	if (cnt.size() == 1) ans1.insert(cnt);
		if (cnt.size() == 2) ans2.insert(cnt);

	cnt.clear();
	for (int i = 0; i < 3; i++) cnt.insert(grid[i][2 - i]);
	if (cnt.size() == 1) ans1.insert(cnt);
	if (cnt.size() == 2) ans2.insert(cnt);

	cout << ans1.size() << '\n' << ans2.size() << '\n';
	return 0;
}
