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

ll pw[1000001], hsh[1000001];
bool vis[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 31 % MOD;
	for (int i = 1; i <= n; i++) hsh[i] = (hsh[i - 1] * 31 + s[i - 1]) % MOD;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) { cout << i << ' '; continue; }
		bool ok = hsh[n % i] == (hsh[n] - hsh[n - n % i] * pw[n % i] % MOD + MOD) % MOD;
		for (int j = i + i; j <= n; j += i)
			if ((hsh[j] - hsh[j - i] * pw[i] % MOD + MOD) % MOD != hsh[i])
				{ ok = false; break; }
		if (ok) {
			for (int j = i + i; j <= n; j += i) vis[j] = true;
			cout << i << ' ';
		}
	}
	cout << '\n';
	return 0;
}
