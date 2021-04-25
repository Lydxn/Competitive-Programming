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

char ans[201][100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, ptr = 100; string s;
	cin >> n >> s;
	memset(ans, '.', sizeof(ans));
	for (int i = 0; i < n; i++) {
		if (s[i] == '+') ans[ptr--][i] = '/';
		else if (s[i] == '-') ans[++ptr][i] = '\\';
		else ans[ptr][i] = '_';
	}

	for (int i = 0; i < 201; i++) {
		if (count(ans[i], ans[i] + n, '.') == n) continue;
		for (int j = 0; j < n; j++) cout << ans[i][j];
		cout << '\n';
	}
	return 0;
}
