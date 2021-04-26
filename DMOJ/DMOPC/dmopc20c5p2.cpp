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

int N, M;

bool f(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N) return false;
	long double a = 1.0 * N / M * x, b = 1.0 * N / M * (x + 1);
	//cout << a << ' ' << b << '\n';
	if (y + 1e-9 < a && a < y + 1 - 1e-9) return true;
	if (y + 1e-9 < b && b < y + 1 - 1e-9) return true;
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int cx = 0, cy = 0;
	cin >> N >> M;
	vector<pii> ans;
	int n = N / __gcd(N, M), m = M / __gcd(N, M);
	for (int i = 0; i < n + m - 1; i++) {
		ans.emplace_back(cx, cy);
		if (f(cx + 1, cy)) ++cx;
		else ++cy;
	}

	cout << N / n * ans.size() << '\n';
	for (int _ = 0; _ < N / n; _++) {
		for (pii i : ans) cout << _ * n + i.second + 1 << ' ' << _ * m + i.first + 1 << '\n';
	}
	return 0;
}
