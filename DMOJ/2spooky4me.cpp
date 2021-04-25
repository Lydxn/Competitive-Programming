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

pii deco[20001];
int diff[20000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, L, S, a, b, s;
	cin >> N >> L >> S;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> s;
		deco[2 * i] = {a, s}, deco[2 * i + 1] = {b + 1, -s};
	}

	deco[2 * N] = {0, 0};
	sort(deco, deco + 2 * N + 1);

	int ans = 0;
	for (int i = 0, sum = 0; i < 2 * N; i++) {
		sum += deco[i].second;
		if (sum >= S) ans += deco[i + 1].first - deco[i].first;
	}
	cout << L - ans << '\n';
	return 0;
}
