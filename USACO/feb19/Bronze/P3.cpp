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

string s[100];
int l[100], r[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> s[i] >> l[i] >> r[i];

	int L = -INF, R = INF;
	for (int i = N - 1; i >= 0; i--) {
		if (s[i] == "none") L = max(L, l[i]), R = min(R, r[i]);
		else if (s[i] == "off") L += l[i], R += r[i];
		else L = max(0, L - r[i]), R = max(0, R - l[i]);
	}
	cout << L << ' ' << R << '\n';

	L = -INF, R = INF;
	for (int i = 0; i < N; i++) {
		if (s[i] == "none") L = max(L, l[i]), R = min(R, r[i]);
		else if (s[i] == "on") L += l[i], R += r[i];
		else L = max(0, L - r[i]), R = max(0, R - l[i]);
	}
	cout << L << ' ' << R << '\n';
	return 0;
}
