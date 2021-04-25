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

struct trie {
	int t[200001][26], tidx;
	trie() { memset(t, -1, sizeof(t)); tidx = 0; }
	void insert(string s) {
		int cur = 0;
		for (char c : s) {
			if (t[cur][c - 'a'] == -1) t[cur][c - 'a'] = ++tidx;
			cur = t[cur][c - 'a'];
		}
	}
} T[2];

bool win(int c1, int c2, int idx) {
	for (int i = 0; i < 26; i++) {
		if (T[idx].t[c1][i] == -1) continue;
		if (T[idx ^ 1].t[c2][i] == -1 || !win(T[idx ^ 1].t[c2][i], T[idx].t[c1][i], idx ^ 1)) return true;
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m; string s;
	cin >> n;
	while (n--) cin >> s, T[0].insert(s);
	cin >> m;
	while (m--) cin >> s, T[1].insert(s);
	cout << (win(0, 0, 0) ? "Nina" : "Emilija") << '\n';
	return 0;
}
