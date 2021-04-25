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

vector<int> r[400001];
map<int, int> mp;
int a[200000], b[200000], p[200000], midx;
ll dp[400001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> p[i], ++b[i];
		mp[a[i]] = mp[b[i]] = 0;
	}

	for (auto &i : mp) i.second = ++midx;
	for (int i = 0; i < n; i++) r[mp[b[i]]].push_back(i);
	for (int i = 1; i <= midx; i++) {
		dp[i] = dp[i - 1];
		for (int j : r[i]) dp[i] = max(dp[i], dp[mp[a[j]]] + p[j]);
	}
	cout << dp[midx] << '\n';
	return 0;
}
