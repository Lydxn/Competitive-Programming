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

unordered_set<string> ss[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);

	int N, K; string S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S >> K;
		while (K--) cin >> S, ss[i].insert(S);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int cnt = 0;
			for (auto k : ss[i]) cnt += ss[j].count(k);
			ans = max(ans, cnt);
		}
	}
	cout << ans + 1 << '\n';
	return 0;
}
