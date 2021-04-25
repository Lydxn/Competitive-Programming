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

int pre[100001], suf[100002];
char pmn[26], smn[26];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b; string S;
	cin >> N >> Q >> S; S = " " + S;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 26; j++) pmn[j] = min(pmn[j], S[i]);
		pre[i] = pre[i - 1] + (pmn[S[i] - 'A'] < S[i]), pmn[S[i] - 'A'] = S[i];
	}
	for (int i = N; i; i--) {
		for (int j = 0; j < 26; j++) smn[j] = min(smn[j], S[i]);
		suf[i] = suf[i + 1] + (smn[S[i] - 'A'] < S[i]), smn[S[i] - 'A'] = S[i];
	}
	while (Q--) {
		cin >> a >> b;
		cout << pre[a - 1] + suf[b + 1] << '\n';
	}
	return 0;
}
