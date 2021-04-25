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
 
int a[5000], b[5000], c[5000], p[5000];
ll d[2501];
 
int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
 
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i] >> b[i] >> c[i];
	memset(d, INFL, sizeof(d)); d[1] = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m; j++)
			if (d[a[j]] + c[j] < d[b[j]])
				d[b[j]] = d[a[j]] + c[j], p[b[j]] = a[j];
	for (int i = 0; i < m; i++) {
		if (d[a[i]] + c[i] < d[b[i]]) {
			p[b[i]] = a[i];
			cout << "YES\n";
			int v = b[i];
			for (int j = 0; j < n; j++) v = p[v];
 
			vector<int> ans; int t = v;
			while (true) {
				v = p[v], ans.push_back(v);
				if (v == t) break;
			}
			reverse(ans.begin(), ans.end());
			for (int j : ans) cout << j << ' ';
			cout << v << '\n';
			return 0;
		}
	}
	cout << "NO\n";	
	return 0;
}