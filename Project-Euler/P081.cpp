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

int dp[80][80];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("p081_matrix.txt", "r", stdin);

	for (int i = 0; i < 80; i++) {
		string s, cur; int j = 0;
		cin >> s; s += ',';
		for (char c : s) {
			if (c == ',') dp[i][j++] = stoi(cur), cur = "";
			else cur += c;
		}
	}

	for (int i = 0; i < 80; i++) {
		for (int j = 0; j < 80; j++) {
			if (i == 0 && j == 0) continue;
			dp[i][j] += min(i ? dp[i - 1][j] : INF, j ? dp[i][j - 1] : INF);
		}
	}
	cout << dp[79][79] << '\n';
	return 0;
}
