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

string s[26];
int N;

void solve(int idx, int L, string tmp) {
	if (L <= 0 || idx >= N) return;

	for (char c : s[idx])
		cout << tmp + c << '\n', solve(idx + 1, L - 1, tmp + c);
	if (idx) solve(idx + 1, L, tmp);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int L, M; char ch;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> M;
		while (M--) cin >> ch, s[i].push_back(ch);
	}

	solve(0, L, "");
	return 0;
}
