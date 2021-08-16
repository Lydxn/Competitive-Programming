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

int cnt[26][26];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll ans = 0; string S;
	cin >> N;
	while (N--) cin >> S, ++cnt[S[0] - 'A'][S.back() - 'A'];
	for (int a = 0; a < 26; a++) {
		for (int b = 0; b < 26; b++) {
			int ab = cnt[a][b]--;
			for (int c = 0; c < 26; c++) {
				int bc = cnt[b][c]--;
				for (int d = 0; d < 26; d++) {
					int dc = cnt[d][c]--;
					ans += ab * bc * dc * cnt[a][d];
					++cnt[d][c];
				}
				++cnt[b][c];
			}
			++cnt[a][b];
		}
	}
	cout << ans << '\n';
	return 0;
}
