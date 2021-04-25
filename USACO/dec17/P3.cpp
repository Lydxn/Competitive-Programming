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

struct cow {
	int t, x; string s;
	bool operator< (const cow &c) { return t < c.t; }
} c[100];
unordered_map<string, int> mp = {{"Bessie", 0}, {"Elsie", 1}, {"Mildred", 2}};
int cnt[3];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	
	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> c[i].t >> c[i].s >> c[i].x;
	sort(c, c + N);
	vector<int> v, prev;
	for (int i = 0; i < N; i++) {
		cnt[mp[c[i].s]] += c[i].x;
		int mx = 0; v.clear();
		for (int j = 0; j < 3; j++) mx = max(mx, cnt[j]);
		for (int j = 0; j < 3; j++)
			if (cnt[j] == mx) v.push_back(j);
		if (v != prev) ++ans;
		prev = v;
	}
	cout << ans << '\n';
	return 0;
}
