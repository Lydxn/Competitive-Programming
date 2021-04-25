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

	freopen("evolution.in", "r", stdin);
	freopen("evolution.out", "w", stdout);

	int N, K; string S;
	unordered_map<string, int> mp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		while (K--) cin >> S, mp[S] |= 1 << i;
	}

	for (auto i : mp) {
		for (auto j : mp) {
			int a = i.second, b = j.second;
			if ((a & b) && (a | b) != a && (a | b) != b) { cout << "no\n"; return 0; }
		}
	}
	cout << "yes\n";
	return 0;
}