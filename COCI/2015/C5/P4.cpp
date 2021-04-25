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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll X;
	cin >> N >> X;
	if (X > 1LL * (N - 1) * (N - 2) / 2) { cout << "-1\n"; return 0; }

	vector<int> in, out;
	for (int i = N - 2; i; i--) {
		if (X >= i) in.push_back(N - i - 1), X -= i;
		else out.push_back(N - i - 1);
	}

	for (int i : out) cout << i << ' ';
	cout << N - 1 << ' ';
	for (int i : in) cout << i << ' ';
	cout << N << '\n';
	return 0;
}
