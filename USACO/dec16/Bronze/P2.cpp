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

pair<string, string> w[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> w[i].first >> w[i].second;

	for (char c = 'a'; c <= 'z'; c++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int cnt1 = 0, cnt2 = 0;
			for (char d : w[i].first) cnt1 += d == c;
			for (char d : w[i].second) cnt2 += d == c;
			cnt += max(cnt1, cnt2);
		}
		cout << cnt << '\n';
	}
	return 0;
}
