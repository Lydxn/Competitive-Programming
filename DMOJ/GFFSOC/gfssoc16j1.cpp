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

int c[4];
unordered_map<string, int> mp = {{"TOK", 1}, {"English", 2}, {"Chemistry", 3}, {"Math", 4}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int C, N; string S;
	cin >> C >> N;
	for (int i = 0; i < C; i++)
		cin >> S, c[i] = mp[S];
	sort(c, c + C);
	for (int i = 0; i < C; i++) {
		if ((N -= c[i]) < 0) {
			cout << "Go to Metro\n" << i << '\n';
			return 0;
		}
	}
	cout << "YEA BOI\n";
	return 0;
}
