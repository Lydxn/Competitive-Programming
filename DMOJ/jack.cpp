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

int p1[200001], p2[200001], spf[200001];
unordered_map<int, int> mp;

ll powmod(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD, y >>= 1;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 200000; i++) spf[i] = i;
	for (int i = 2; i * i <= 200000; i++)
		if (spf[i] == i)
			for (int j = i * i; j <= 200000; j += i)
				if (spf[j] == j) spf[j] = i;

	int N, a;
	cin >> N;
	while (N--) {
		cin >> a;
		mp.clear();
		while (a != 1) ++mp[spf[a]], a /= spf[a];
		for (auto i : mp) p1[i.first] = max(p1[i.first], i.second), p2[i.first] += i.second;
	}

	int ans = 1;
	for (int i = 2; i <= 200000; i++) {
		int d = p2[i] - p1[i];
		if (d) ans = ans * powmod(i, d) % MOD;
	}
	cout << ans + 1 << '\n';
	return 0;
}
