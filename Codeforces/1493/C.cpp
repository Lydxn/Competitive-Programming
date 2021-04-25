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

int k, cnt[26];

int left(int x) { return (k - cnt[x] % k) % k; }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, n; string s;
	cin >> T;
	while (T--) {
		cin >> n >> k >> s;
		if (n % k) { cout << "-1\n"; continue; }
		
		memset(cnt, 0, sizeof(cnt));
		for (char c : s) ++cnt[c - 'a'];
		
		int cur = 0;
		for (int i = 0; i < 26; i++) cur += left(i);
		if (cur == 0) { cout << s << '\n'; continue; }
		
		for (int i = n - 1; i >= 0; i--) {
			cur -= left(s[i] - 'a'), --cnt[s[i] - 'a'], cur += left(s[i] - 'a');
			for (int j = s[i] - 'a' + 1, tmp = cur; j < 26; j++) {
				cur -= left(j), ++cnt[j], cur += left(j);
				if (n - i - 1 >= cur) {
					for (int x = 0; x < i; x++) cout << s[x];
					cout << char(j + 'a');

					string ans;
					for (int x = 0; x < 26; x++) ans += string(left(x), x + 'a');
					while (int(ans.size()) < n - i - 1) ans += 'a';
					sort(ans.begin(), ans.end());
					cout << ans << '\n';
					goto nxt;
				}
				cur = tmp, --cnt[j];
			}
		}
		nxt:;
	}
	return 0;
}
