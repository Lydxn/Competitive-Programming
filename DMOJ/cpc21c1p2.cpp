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

ull A[400001], B[400001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ull ans = 0;
	cin >> N;
	for (int i = 0; i < 2 * N + 1; i++) cin >> A[i];
	for (int i = 0; i < 2 * N + 1; i++) cin >> B[i];
	for (int i = 0; i < 63; i++) {
		int ca = 0, cb = 0;
		for (int j = 0; j < 2 * N + 1; j++)
			ca += (A[j] >> i) & 1, cb += (B[j] >> i) & 1;
		if (2 * N + 1 - ca == cb) ans |= 1LL << i;
		else if (ca != cb) { cout << "-1\n"; return 0; }
	}
	for (int i = 0; i < 2 * N + 1; i++) A[i] ^= ans;
	sort(A, A + 2 * N + 1), sort(B, B + 2 * N + 1);
	for (int i = 0; i < 2 * N + 1; i++)
		if (A[i] != B[i]) { cout << "-1\n"; return 0; }
	cout << ans << '\n';
	return 0;
}