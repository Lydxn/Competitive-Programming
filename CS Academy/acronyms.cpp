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

string S[100000];
int freq[26], freq2[26];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i], ++freq[S[i][0] - 'a'];

	int ans = 0;
	for (int i = 0; i < N; i++) {
		memset(freq2, 0, sizeof(freq2));
		for (char c : S[i]) ++freq2[c - 'a'];
		++freq2[S[i][0] - 'a'];

		bool bad = false;
		for (int i = 0; i < 26; i++) bad |= freq[i] < freq2[i];
		ans += !bad;
	}
	cout << ans << '\n';
	return 0;
}
