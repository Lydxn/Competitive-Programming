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

int A[6], B[6];

ld f(int *P, ld x) {
	ld res = 0;
	for (int i = 0; i < 6; i++) res += pow(x, i) * P[i];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N;
	for (int i = N; i >= 0; i--) cin >> A[i];
	cin >> M;
	for (int i = M; i >= 0; i--) cin >> B[i];

	ld a, b, mid;
	cin >> a >> b;

	if (f(A, a) == f(B, a)) { cout << a << '\n'; return 0; }
	if (f(A, a) < f(B, a)) swap(A, B);

	for (int iter = 0; iter < 100; iter++) {
		mid = (a + b) / 2;
		if (f(A, mid) > f(B, mid)) a = mid;
		else b = mid;
	}

	cout << fixed << setprecision(10) << mid << ' ' << '\n';
	return 0;
}
