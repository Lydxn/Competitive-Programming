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

const int BASE = 31;
ll hsh[1000001], rhsh[1000001], p[1000001];

int f0(int l, int r) { return (hsh[r] - hsh[l - 1] * p[r - l + 1] % MOD + MOD) % MOD; }
int f1(int l, int r) { return (rhsh[l] - rhsh[r + 1] * p[r - l + 1] % MOD + MOD) % MOD; }

void solve() {
	string S;
	cin >> S;

	int sz = S.size();
	hsh[0] = rhsh[sz + 1] = 0;
	for (int i = 1; i <= sz; i++) hsh[i] = (hsh[i - 1] * BASE + S[i - 1]) % MOD;
	for (int i = sz; i; i--) rhsh[i] = (rhsh[i + 1] * BASE + S[i - 1]) % MOD;

	for (int i = sz >> 1; i; i--) {
		if (f0(1, i) == f1(i + 1, i * 2) || f0(sz - i * 2 + 1, sz - i) == f1(sz - i + 1, sz))
			{ cout << sz - i * 2 << '\n'; break; }
		if (f0(1, i) == f1(i, i * 2 - 1) || f0(sz - i * 2 + 2, sz - i + 1) == f1(sz - i + 1, sz))
			{ cout << sz - i * 2 + 1 << '\n'; break; }
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	p[0] = 1;
	for (int i = 1; i <= 1000000; i++) p[i] = p[i - 1] * BASE % MOD;
	for (int _ = 0; _ < 10; _++) solve();
	return 0;
}
