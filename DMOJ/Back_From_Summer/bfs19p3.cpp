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

int freq[26], freq2[27], K;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S; int L, sz; ll ans = INFL;
	cin >> S >> L >> K; sz = S.size();
	if (L + K >= sz) { cout << "0\n"; return 0; }
	for (int i = L; i < sz; i++) ++freq[S[i] - 'a'];
	for (int i = L; i <= sz; i++) {
		memcpy(freq2, freq, 104), sort(freq2, freq2 + 26, greater<int>());
		int sum = K;
		for (int j = 1; j <= 26; j++) {
			int p = (freq2[j - 1] - freq2[j]) * j;
			if (sum >= p) sum -= p;
			else {
				ll sub = freq2[j - 1] - sum / j;
				ll res = sub * sub * (j - sum % j) + (sub - 1) * (sub - 1) * (sum % j);
				for (int k = j; k < 26; k++) res += 1LL * freq2[k] * freq2[k];
				ans = min(ans, res);
				break;
			}
		}
		if (i != sz) --freq[S[i] - 'a'], ++freq[S[i - L] - 'a'];
	}
	cout << ans << '\n';
	return 0;
}
