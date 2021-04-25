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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("records.in", "r", stdin);
	freopen("records.out", "w", stdout);

	int N; string s[3]; unordered_map<string, int> cnt;
	cin >> N;
	while (N--) {
		cin >> s[0] >> s[1] >> s[2]; sort(s, s + 3);
		cnt[s[0] + " " + s[1] + " " + s[2]]++;
	}

	int mx = 0;
	for (auto i : cnt) mx = max(mx, i.second);
	cout << mx << '\n';
	return 0;
}
