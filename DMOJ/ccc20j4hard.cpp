// WIP

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
const ll MOD = 1LL << 55;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

// plz i just want to pass with polyhash
const int BASE = 131;
const ll MOD0 = (1LL << 55) - 1;
gp_hash_table<ll, null_type> ss;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string T, S; ll pw = 1, shsh = 0, thsh = 0;
	cin >> T >> S;
	int tlen = T.size(), slen = S.size(); S += S;
	assert(1 <= tlen && tlen <= 10000000); assert(1 <= slen && slen <= 10000000);
	for (int i = 0; i < slen - 1; i++) pw = pw * BASE % MOD;
	for (int i = 0; i < slen; i++) thsh = (thsh * BASE + T[i] - 64) & MOD0;
	for (int i = 0; i < slen; i++) shsh = (shsh * BASE + S[i] - 64) & MOD0;
	for (int i = 0; i < slen; i++) ss.insert(shsh), shsh = (((shsh - (S[i] - 64) * pw + 26 * MOD) & MOD0) * BASE + S[i + slen] - 64) & MOD0;
	for (int i = 0; i <= tlen - slen; i++) {
		if (ss.find(thsh) != ss.end()) { cout << "yes\n"; return 0; }
		thsh = (((thsh - (T[i] - 64) * pw + 26 * MOD) & MOD0) * BASE + T[i + slen] - 64) & MOD0;
	}
	cout << "no\n";
	return 0;
}