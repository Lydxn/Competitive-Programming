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

double D[100000], K;
int N;

bool f(double x) {
	double start = D[0] + x;
	for (int i = 1; i < N; i++) {
		if (D[i] - x - start > K) return false;
		start = min(start + K, D[i] + x);
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> N;
	for (int i = 0; i < N; i++) cin >> D[i];

	double l = 0, r = 1e9, mid;
	for (int iter = 0; iter < 50; iter++) {
		mid = (l + r) / 2;
		if (f(mid)) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(6) << l << '\n';
	return 0;
}
