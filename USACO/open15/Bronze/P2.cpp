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

int f[7][2];
string s = "BESIGOM";

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("geteven.in", "r", stdin);
	freopen("geteven.out", "w", stdout);

	int N, x, ans = 0; char c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c >> x;
		++f[s.find(c)][x % 2 != 0];
	}

	for (int B = 0; B < 2; B++)
	for (int E = 0; E < 2; E++)
	for (int S = 0; S < 2; S++)
	for (int I = 0; I < 2; I++)
	for (int G = 0; G < 2; G++)
	for (int O = 0; O < 2; O++)
	for (int M = 0; M < 2; M++)
		if ((B+E+S+S+I+E) * (G+O+E+S) * (M+O+O) % 2 == 0)
			ans += f[0][B] * f[1][E] * f[2][S] * f[3][I] * f[4][G] * f[5][O] * f[6][M];
	cout << ans << '\n';
	return 0;
}

