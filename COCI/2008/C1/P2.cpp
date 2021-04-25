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

pair<int, string> ans[3] = {{0, "Adrian"}, {0, "Bruno"}, {0, "Goran"}};
vector<int> cycle[3] = {{0, 1, 2}, {1, 0, 1, 2}, {2, 2, 0, 0, 1, 1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string S;
	cin >> N >> S;
	for (int i = 0; i < int(S.size()); i++) {
		for (int j = 0; j < 3; j++) {
			ans[j].first += cycle[j][i % cycle[j].size()] == S[i] - 'A';
		}
	}

	sort(ans, ans + 3);
	int M = ans[2].first;
	cout << M << '\n';
	for (int i = 0; i < 3; i++)
		if (ans[i].first == M) cout << ans[i].second << '\n';
	return 0;
}
