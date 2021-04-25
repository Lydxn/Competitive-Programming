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

double a[4], b[4], c[4];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int mx = 0;
	for (int i = 0; i < 4; i++) {
		cin >> a[i] >> b[i] >> c[i];
		if (c[mx] < c[i]) mx = i;
	}

	a[mx] = s == "trees!" ? b[mx] : 0;
	double ans = 0;
	for (int i = 0; i < 4; i++) ans += a[i] / b[i] * c[i];
	cout << round(ans * 100) << '\n';
	return 0;
}
