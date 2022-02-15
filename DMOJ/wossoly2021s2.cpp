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

int cnt[8];

int f(int c) {
	return c == 'R' ? 1 : c == 'G' ? 2 : 4;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string s0, s1, s2, s3;
	cin >> N >> s0 >> s1 >> s2 >> s3;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 8; j++)
			if ((j & (f(s0[i]) | f(s2[i]))) == j)
				++cnt[j];
	ll ans = 0;
	for (int i = 0; i < N; i++) ans += cnt[(f(s1[i]) | f(s3[i])) ^ 7];
	cout << ans << '\n';
	return 0;
}
