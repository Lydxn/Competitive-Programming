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

#define SCORE(s) ('2' <= s[0] && s[0] <= '9' ? s[0] - '0' : 10)

bool r7, r8, r9, r10, r11, r12;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s[5]; int ans = 0, mod = 0;
	for (int i = 0; i < 5; i++) cin >> s[i], ans += SCORE(s[i]);

	// rule 1
	++ans; int cntj = 0;
	for (int i = 0; i < 5; i++) cntj += s[i][0] == 'J';
	ans += cntj * SCORE(s[0]), ++mod;

	// rule 2
	ans *= 2, ++mod;

	// rule 3
	int msk = 0; unordered_map<char, int> mp = {{'D', 0}, {'H', 1}, {'C', 2}, {'S', 3}};
	for (int i = 0; i < 5; i++) msk |= 1 << mp[s[i].back()];
	if (msk == 15) ans *= 2, ++mod;

	// rule 4
	int cntb = 0;
	for (int i = 0; i < 5; i++) cntb += s[i].back() == 'C' || s[i].back() == 'S';
	ans += abs(2 * cntb - 5), ++mod;

	// rule 5
	// do nothing

	// rule 6
	int cnt7 = 0;
	for (int i = 0; i < 5; i++) cnt7 += s[i][0] == '7';
	if (cnt7 == 4) ans -= 121, ++mod;

	// rule 7
	g7:;
	if (ans >= 0) {
		int mn = INF;
		for (int i = 0; i < 5; i++) mn = min(mn, SCORE(s[i]));
		ans += mn, ++mod, r7 = true;
	}

	// rule 8
	g8:;
	if (ans < 0) ans *= -1, ++mod, r8 = true;

	// rule 9
	g9:;
	int cntd = 0;
	for (int i = 0; i < 5; i++) cntd += s[i].back() == 'D';
	if (cntd >= 3) {
		++ans, ++mod, r9 = true;
		for (int i = 0; i < 5; i++) {
			if (s[i][0] == '2') s[i][0] = '5';
			else if (s[i][0] == '5') s[i][0] = '2';
			else if (s[i][0] == '6') s[i][0] = '9';
			else if (s[i][0] == '9') s[i][0] = '6';
		}
	}

	// rule 10
	g10:;
	unordered_set<char> ss; bool all10 = true;
	for (int i = 0; i < 5; i++) ss.insert(s[i][0]), all10 &= SCORE(s[i]) == 10;
	if (all10 && ss.size() == 5) ans += 5, ++mod, r10 = true;

	// rule 11
	g11:;
	int pop = 0;
	if (mod > 8) pop = __builtin_popcount(ans), ans += pop, ++mod, r11 = true;

	// rule 12
	bool rnk2 = false;
	for (int i = 0; i < 5; i++) rnk2 |= s[i][0] == '2';
	if (rnk2 && !r12) {
		r12 = true;
		if (r11) goto g11;
		if (r10) goto g10;
		if (r9) goto g9;
		if (r8) goto g8;
		if (r7) goto g7;
	}

	// rule 13
	if (rnk2) ans += ans;

	cout << ans << '\n';
	return 0;
}
