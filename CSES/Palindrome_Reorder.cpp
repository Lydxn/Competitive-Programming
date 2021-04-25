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

int freq[26];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	for (char c : s) ++freq[c - 'A'];

	int odd = 0;
	for (int i = 0; i < 26; i++) odd += freq[i] % 2;
	if (odd > 1) {
		cout << "NO SOLUTION\n";
		return 0;
	}

	string ans = "";
	for (int i = 0; i < 26; i++)
		if (!(freq[i] % 2))
			for (int j = 0; j < freq[i] / 2; j++)
				ans.push_back(i + 'A');

	cout << ans;
	for (int i = 0; i < 26; i++)
		if (freq[i] % 2)
			cout << string(freq[i], i + 'A');
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
	return 0;
}
