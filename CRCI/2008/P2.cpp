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

string friends[50];

int pts(char a, char b) {
	if (a == b) return 1;
	if ((a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R')) return 2;
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, N; string sven;
	cin >> R >> sven >> N;
	for (int i = 0; i < N; i++) cin >> friends[i];

	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < N; j++)
			ans1 += pts(sven[i], friends[j][i]);

		int cur = 0;
		for (char c : "RPS") {
			int p = 0;
			for (int j = 0; j < N; j++)
				p += pts(c, friends[j][i]);
			cur = max(cur, p);
		}
		ans2 += cur;
	}
	cout << ans1 << '\n' << ans2 << '\n';
	return 0;
}
