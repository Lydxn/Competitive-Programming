// barely passes lol

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

int f[100001], N;
ordered_set<pii> BIT[100002];
unordered_map<int, set<int>> mp;

void insert(int i, int j) { for (int ii = i; ii <= N + 1; ii += ii & -ii) BIT[ii].insert({j, i}); }
void erase(int i, int j) { for (int ii = i; ii <= N + 1; ii += ii & -ii) BIT[ii].erase({j, i}); }
int query(int i, int x) { int res = 0; for (; i; i -= i & -i) res += BIT[i].order_of_key({x + 1, 0}); return res; }
int query(int i, int j, int l, int r) { return query(j, r) - query(i - 1, r) - query(j, l - 1) + query(i - 1, l - 1); }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q, op, a, b;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> f[i], mp[f[i]].insert(i);
	for (int i = 1; i <= N; i++) {
		auto it = mp[f[i]].find(i); ++it;
		insert(i, it == mp[f[i]].end() ? N + 1 : *it);
	}

	while (Q--) {
		cin >> op >> a >> b;
		if (op == 1) {
			auto prev0 = mp[f[a]].lower_bound(a), nxt0 = mp[f[a]].upper_bound(a);
			auto prev1 = mp[b].lower_bound(a), nxt1 = mp[b].upper_bound(a);

			if (prev0 != mp[f[a]].begin())
				--prev0, erase(*prev0, a), insert(*prev0, nxt0 == mp[f[a]].end() ? N + 1 : *nxt0);
			if (prev1 != mp[b].begin())
				--prev1, erase(*prev1, nxt1 == mp[b].end() ? N + 1 : *nxt1), insert(*prev1, a);
			erase(a, nxt0 == mp[f[a]].end() ? N + 1 : *nxt0), insert(a, nxt1 == mp[b].end() ? N + 1 : *nxt1);

			mp[f[a]].erase(a), mp[b].insert(a), f[a] = b;
		} else
			cout << query(a, b, b + 1, N + 1) << '\n';
	}
	return 0;
}
