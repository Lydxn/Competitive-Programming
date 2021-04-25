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

int N;
char G[18][18];
unordered_set<string> ss1[18], ss2[18];
string s;

void solve1(int r, int c) {
	if (r + c == N - 1) ss1[r].insert(s + G[r][c]);
	else {
		s.push_back(G[r][c]); solve1(r + 1, c); s.pop_back();
		s.push_back(G[r][c]); solve1(r, c + 1); s.pop_back();
	}
}

void solve2(int r, int c) {
	if (r + c == N - 1) ss2[r].insert(s + G[r][c]);
	else {
		s.push_back(G[r][c]); solve2(r - 1, c); s.pop_back();
		s.push_back(G[r][c]); solve2(r, c - 1); s.pop_back();
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("palpath.in", "r", stdin);
	freopen("palpath.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> G[i][j];

	s = ""; solve1(0, 0);
	s = ""; solve2(N - 1, N - 1);

	unordered_set<string> ans;
	for (int i = 0; i < N; i++)
		for (auto j : ss1[i])
			if (ss2[i].count(j)) ans.insert(j);
	cout << ans.size() << '\n';
	return 0;
}
