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

int c[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll ans = 0; string S;
	cin >> N >> S; S += "\0";
	for (int i = 0, j = 0; i <= N; i++) {
		if (!i || S[i] == S[i - 1]) ++j;
		else {
			for (int k = i - 1; k >= i - j; k--) c[k] = j;
			j = 1;
		}
	}
	for (int i = 0; i < N; i++) ans += min(c[i], min(i + 1, N - i));
	for (int i = 1; i < N; i++) ans += min(max(c[i], c[i - 1]), min(i, N - i));
	cout << ans << '\n';
	return 0;
}
